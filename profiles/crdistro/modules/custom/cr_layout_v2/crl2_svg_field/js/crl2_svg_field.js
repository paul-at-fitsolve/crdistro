/**
 * Behaviour for the RND15 SVG compatibility and fallback.
 *
 * Author: Carl Hinton, for Comic Relief.
 * Contributors: J. Pitt
 *
 * Last update: 27th January 2015
 *
 * Description & additional notes:
 *
 * - SVG is output as a span and the JS then triggers the load
 *
 */
(function (w, parent) {

  // Enable strict mode.
  "use strict";

  // Declare svg support variable
  var svgSupport = document.implementation.hasFeature("http://www.w3.org/TR/SVG11/feature#Image", "1.1");

  w.initSVG = function (parent) {
    var elems = document.querySelectorAll("[data-svg]");
    var len = elems.length;
    var visible = '';
    var svgSrc = null;
    var svgImg = null;
    for (var i = 0; i < len; i++) {
      if(!svgSupport) {
        elems[i].parentNode.removeChild(elems[i]);
        continue;
      }

      // Handle the loading of SVGs in normal browsers
      visible = elems[i].currentStyle ? elems[i].currentStyle.display : getComputedStyle(elems[i], null).display;
      svgSrc = elems[i].getAttribute('data-src');

      // Find any existing img element in the picture element.
      svgImg = elems[i].getElementsByTagName('img')[0];

      // Check if the element is visible and assign the proper SVG source
      if(visible !== 'none' && elems[i].src !== svgSrc) {

        // Add a new img element if one doesn't exist.
        if (!svgImg) {
          svgImg = w.document.createElement('img');
          elems[i].appendChild(svgImg);
        }

        // Set the source :)
        svgImg.src = svgSrc;
      }
    }
  };

  // Run on domready (w.load as a fallback)
  if (w.addEventListener) {
    w.addEventListener('resize', w.initSVG, false);
    w.addEventListener('DOMContentLoaded', function () {
      w.initSVG();
      // Run once only.
      w.removeEventListener('load', w.initSVG(), false);
    }, false);
    w.addEventListener('load', w.initSVG(), false);
  }
  else if (w.attachEvent) {
    w.attachEvent('onload', w.initSVG());
  }

})(this);