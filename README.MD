
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
