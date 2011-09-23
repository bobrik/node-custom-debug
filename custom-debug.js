var debug = require("./build/default/debugger");

var started = false;

exports.start = function(port) {
    if (!started) {
        started = true;
        return debug.start(port);
    }

    return false;
}

exports.isStarted = function() {
    return started;
}
