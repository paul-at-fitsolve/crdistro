CR Layout v2 Downloadables
==========================
Module to provide tokens for downloadables based on CR Layout v2

Tokens are provided in the following form:
 [dl:machine_name:token_type{:optional_modifier}]

machine_name
------------
The download is give a label/ title on creation and this will in turn
generate a machine readable name shown to the right of the label field.

This machine name is used to identify the downloadable being used.

token_type
----------
Specifies the type of token or the aspect of the download to be displayed.

The following are currently available:

- size
- url
- type
- link
- title

In addition some of the tokens have additional modifiers that tweak the data
displayed.

optional_modifier
-----------------
Some token_types provide optional modifiers for tweaking the replacement output,
these are described below:

size - integer precision modifier
type - lowercase, uppercase (default), camelcase
title - lowercase, uppercase (default), camelcase

Examples
---------
Consider a downloadable created using a local file on cr-example.com with:

 hello.jpg - filename
 183.844 KB - size
 "Test Pic File" - human-readable title

The following is entered into field using token replacement:

size = [dl:test_pic_file:size]
size = [dl:test_pic_file:size:3]
link = [dl:test_pic_file:link]
url  = [dl:test_pic_file:url]
type = [dl:test_pic_file:type]
type = [dl:test_pic_file:type:lowercase]
title = [dl:test_pic_file:title]
title big = [dl:test_pic_file:title:uppercase]

output produced will be:

size = 183.84 KB
size = 183.844 KB
link = <a href="http://cr-example.com/files/downloadables/hello.jpg" class="download">Test Pic File</a>
url  = http://cr-example.com/files/downloadables/hello.jpg
type = JPG
type = jpg
title = Test Pic File
title big = TEST PIC FILE

CDN
---
If a CDN was configured on the site with a cloudfront URL of http://cloudmeup123
the url and link output would be:

link: <a href="http://cloudmeup123/files/downloadables/hello.jpg" class="download">Test Pic File</a>
url : http://cloudmeup123/files/downloadables/hello.jpg

External URL field
-------------------
If an external URL was used and no local file detected the external URL will be used.

If both a local and an external URL are specified the locally detected file will provide the URL.