// IOS Fix
// https://github.com/WickyNilliams/enquire.js/issues/79
(function () {
    // Skip for non touch devices
    if((typeof Modernizr == 'undefined') || !Modernizr.touch) return;

    if (document.addEventListener) {
        document.addEventListener('DOMContentLoaded', function () {
            var shim = document.createElement('div');
            shim.id = 'ios7-matchMedia-fix';
            document.body.appendChild(shim);

            var timer,
                forceReflow = function () {
                    shim.style.width = (window.innerWidth / 2) + 'px';
                },
                onResize = function () {
                    clearTimeout(timer);
                    timer = setTimeout(forceReflow, 0);
                };

            window.addEventListener('resize', onResize, false);
        });
    }
})();