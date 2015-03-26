JP: 11/7/14
-----------
This feature provides match height (equal heights) for panes.

Further information on the wiki:
http://wiki.comicrelief.com/wiki/RND15_Technical_Documentation#RND15_Technical_Documentation

The feature relies on:
crl2_breakpoints
crl2_matchheight
crl2_pane_styles

The feature works by allowing users to group panes. This sets a data attribute 'date-mh' and ensures these have the same height IF they are in the same row.

How to Match Height of Panes
--------
To use match height on panes, simply set the style settings of a pane and tick the "Use Match Height" checkbox.

Select an existing group or select the "New Group" option in the drop down. Once selected, enter a new name for the group in the textfield.

Groups are saved in a variable and shared site wide.

Hit save and view the results. Every breakpoint it hits, it should trigger an update. On fluid, it will run on an interval of 120ms.

How to Match Height by class
--------
Please see the CRL2 match height documentation.

Implementation Notes:
--------
Shared Pane Groups:
Currently there is no way of editing or deleting the groups. I recommend simply using Devel's Variable Editor: 
/devel/variable