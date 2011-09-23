## node-custom-debug

You have no need to fix your daemon's init scripts to enable debugging and profiling on the fly

### Installation

`npm install -g custom-debug`

### Usage

See `test.js`:

```javascript
var debug    = require("./custom-debug");
var profiler = require("v8-profiler");


var port = 5858;

console.log("Starting first time  : " + debug.start(port));
console.log("Starting second time : " + debug.start(port));

setInterval(function() {
    console.log("Another iteration..");
}, 1000);
```

To try that out:

1. Run `node test.js`
2. Run `node-inspector`
3. Open your browser with the next link: http://localhost:8080/debug?port=58585

---
### Authors
- Ian Babrou (ibobrik@gmail.com)
