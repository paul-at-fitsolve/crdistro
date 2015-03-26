PB: 8/8/14
-----------

This module provides a file field formatter that will display the contents of
an uploaded SVG file as an SVG.

It outputs this: <img src="mysvg.svg" />

See: http://wiki.comicrelief.com/wiki/RND15_Technical_Documentation#SVG_Field


Usage
-----

1. To add an SVG file formatter to an entity, go to the Manage Fields page of your entity.

2. Add a file field to the entity. Ensure 'Allowed filetypes' on the final field settings is set to svg.

3. Go to the Manage Display page for this entity

4. Select "Display SVG" from the Format box next to the file field.

6. Click Save at the bottom of the page.

7. Create an entity and upload a SVG file. When viewing the entity, you
   should see the SVG being rendered.


Troubleshooting
---------------

If the SVG is not being rendered, double-check you've set the display formatter for the
field on the Manage Display page for the entity you're working with.