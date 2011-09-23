var debug    = require("./custom-debug");
var profiler = require("v8-profiler");


var port = 5858;

console.log("Starting first time  : " + debug.start(port));
console.log("Starting second time : " + debug.start(port));

setInterval(function() {
    console.log("Another iteration..");
}, 1000);
