JP: 11/7/14
-----------
This feature provides match height (equal heights) site wide.

Further information on the wiki:
http://wiki.comicrelief.com/wiki/CR_Layout_V2#Match_Height

The js library we are using is the jQuery Match Height. For more info visit this site:
http://brm.io/jquery-match-height/

The feature relies on:
crl2_breakpoints

The feature works by allowing users to match the height of two elements.

How to Match Height of Panes
--------
Use the panel match height feature which allows you to group panes using the panel style plugin.

How to Match Height by class
--------
To Do

Performance & Implementation Notes:
--------
To make this performant, we are using ENQUIRE JS to change the throttling of how often the script checks equal heights.

Basicaly it runs as follow:
XS = Throttle to run every 120ms
SM > Throttle to run every 1000ms (1s)

Troubleshooting:
--------
The IPE implementation is a bit bugy. When using the IPE editor always ensure to refresh the page after save to get a true reflection of the match height script.