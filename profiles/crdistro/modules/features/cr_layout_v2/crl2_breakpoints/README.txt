JP: 21/08/14
-----------
This feature provides functionality to view and track Breakpoints in JS.

The breakpoints are set in the CMS via the Breakpoint Module.

It also provideds the users active and previous breakpoints in the crl2 Drupal Settings object.

Further information on the wiki:
http://wiki.comicrelief.com/wiki/RND15_Technical_Documentation#RND15_Technical_Documentation

For the breakpoint eventing handling please refer to their documentation page:
http://wicky.nillia.ms/enquire.js/

Breakpoint Variables:
--------
The breakpoint variables are exposed as a JS object:

Drupal.settings.crl2.breakpoints

E.g.:
Drupal.settings.crl2.breakpoints.xs
Drupal.settings.crl2.breakpoints.sm
Drupal.settings.crl2.breakpoints.md
Drupal.settings.crl2.breakpoints.lg

Active and Previous Breakpoints:
--------
The breakpoints module has been extended to provide Drupal JS Settings of the users 
active and previous breakpoints. This is handled in crl2.breakpoints.js. The names are:

Drupal.settings.crl2.breakpointFrom
Drupal.settings.crl2.breakpointActive

Example:
if(Drupal.settings.crl2.breakpointActive === 'xs') {
  console.log('we are on mobile!');
}

Breakpoint Event Handling Using Enquire.js
--------
As it's an event handler, ensure you only run this once. 

If you do not need it anymore, make sure you remove the event handler.

Here is an example of handling the Medium (MD) breakpoint:

enquire.register(Drupal.settings.crl2.breakpoints.md, {
  deferSetup : true,
  setup : function() {
    console.log('Setup the MD breakpoint');
  },
  match : function() {
    console.log('We have just matched the md breakpoint');
  },
  unmatch : function() {
    console.log('We have just un matched the md breakpoint');
  }
});