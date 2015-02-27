Version 7.1.7 
Changes
Fix Saving / updating image / image preview 
throw error due to changes in filefield saving
function

Version 7.1.8
Fix missing node in node_api functions causing
slider cannot auto refresh when node do cruds

Fix Nasty bug missing query->fetchAll();

Improve the node loading by using node_load_multiple

Version 7.1.9
Fix node_api's &$node to $node eliminating error
Fix empty slider block throwing error
Now $enabled in vtslide_fetch_data will default to enabled
Known Bugs - If node has 2 languages and not all languages is set to disabled
             then the node will still be shown in the slider.

Version 7.1.10
Added break on foreach loop when altering form