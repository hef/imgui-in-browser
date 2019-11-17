
How To Build
============

    docker build . -t emenv
    docker run -it -v $PWD:/build  emenv
    scons

Your build artifacts will now be in `out/`

Combine the `shell.html` from the project root with the build artifacts to see the result.
You can just copy `shell.html` into the `out/` folder and open shell.html in a browser window.
Firefox will open the app as-is form a file path.  Chrome and Safari both require a webserver.
Try [Caddy](https://caddyserver.com/) for a fast in place webserver.


Debugging
=========

  * Docker is not part of my debugging workflow.  It's there to make builds reproduceable and documented
  * Install and activate the [emsdk](https://emscripten.org/docs/getting_started/downloads.html). Add the appropriate emsdk_env file for  your platform.
  * Copy shell.html to index.html in the project root. Don't use the `out/` folder here.
  * run scons as `scons RELEASE=0 EMSDK=/path/to/your/emsdk OUTDIR=$PWD`
    * We are not using the `out/` folder.  This will help make sourcemaps line up.
    * The params to scons are sticky. You can just run `scons` going forward.
  * run [Caddy](http://caddyserver.com/) in the project root.
    * We are not using the `out/` folder.  This is so that sourcemaps line up correctly.
  * Go to the caddy webserver in your browser, by default it's at [http://localhost:2015](http://localhost:2015)
  * Open the Developer Tools for your browser.
    * The *Console* tab is helpful for finding things that have gone wrong.
    * Under the *Sources* tab, you can navigate cpp files, and place breakpoints.
    * Debugging appears to work fine.
    * Chrome appears to have a slightly better debugger as far as being able to click on callstacks and jump to code.
