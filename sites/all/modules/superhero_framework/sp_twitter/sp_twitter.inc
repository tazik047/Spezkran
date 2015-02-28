<?php

require_once 'sources/twitteroauth.php';
function getConnectionWithAccessToken($cons_key, $cons_secret, $oauth_token, 			$oauth_token_secret) {
		$connection = new TwitterOAuth($cons_key, $cons_secret, $oauth_token, $oauth_token_secret);
		return $connection;
}
function sp_twitter_get_tweets()
{
	$oauth_access_token        = variable_get('sp_twitter_block_access_token');
	$oauth_access_token_secret = variable_get('sp_twitter_block_access_token_secret');
	$consumer_key              = variable_get('sp_twitter_block_consumer_key');
	$consumer_secret           = variable_get('sp_twitter_block_consumer_secret');
	$base_url                  = 'https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=';
	$screen_name 			= variable_get('sp_twitter_block_name');
	$count 					= variable_get('sp_twitter_block_count');
	$connection = getConnectionWithAccessToken($consumer_key, $consumer_secret, $oauth_access_token, $oauth_access_token_secret);
	$results = $connection->get($base_url.$screen_name."&count=".$count);
	$tweets = array();
	if(is_array($results))
	foreach($results as $t){
		$tweet = new stdClass();
		$tweet->name = $t->user->name;
		$tweet->text = $t->text;
		$tweet->created = __prettyDate($t->created_at);
		$tweet->avatar = $t->user->profile_image_url;
		$tweets[] = $tweet;
	}
	return $tweets;
}

function __prettyDate($time)
{
  return Date_Difference::getStringResolved($time);
}

class Date_Difference
{
    public static function getStringResolved($date, $compareTo = NULL)
    {
        if(!is_null($compareTo)) {
            $compareTo = new DateTime($compareTo);
        }
        return self::getString(new DateTime($date), $compareTo);
    }

    public static function getString(DateTime $date, DateTime $compareTo = NULL)
    {
        if(is_null($compareTo)) {
            $compareTo = new DateTime('now');
        }
        $diff = $compareTo->format('U') - $date->format('U');
        $dayDiff = floor($diff / 86400);

    	if(is_nan($dayDiff) || $dayDiff < 0) {
    		return '';
        }
    			
    	if($dayDiff == 0) {
            if($diff < 60) {
                return 'Just now';
            } elseif($diff < 120) {
                return '1 minute ago';
            } elseif($diff < 3600) {
                return floor($diff/60) . ' minutes ago';
            } elseif($diff < 7200) {
                return '1 hour ago';
            } elseif($diff < 86400) {
                return floor($diff/3600) . ' hours ago';
            }
        } elseif($dayDiff == 1) {
            return 'Yesterday';
        } elseif($dayDiff < 7) {
            return $dayDiff . ' days ago';
        } elseif($dayDiff == 7) {
            return '1 week ago';
        } elseif($dayDiff < (7*6)) { // Modifications Start Here
            // 6 weeks at most
            return ceil($dayDiff/7) . ' weeks ago';
        } elseif($dayDiff < 365) {
            return ceil($dayDiff/(365/12)) . ' months ago';
        } else {
            $years = round($dayDiff/365);
            return $years . ' year' . ($years != 1 ? 's' : '') . ' ago';
        }
    }
}