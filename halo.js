const http = require("http");
const v8 = require("v8");
const heapStats = v8.getHeapStatistics();

http.createServer(function(req, res){
    res.writeHead(200, {"Content-Type": "text/html"});
    res.end("heap size limit ");
}).listen(8080);