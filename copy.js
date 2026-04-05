import http from 'http';
import fs from 'fs';
import path from 'path';
import v8 from 'v8';
import { fileURLToPath } from 'url';
import config from './config.js';

// const http = require('http');
// const fs = require('fs');
// const path = require('path');
// const v8 = require('v8');
// const fileURLToPath = require('url');
// const config = require('./config.js');

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const heapStats = v8.getHeapStatistics();

const server = http.createServer((req, res) => {
    const filepath = path.join(__dirname, "README.md");

    fs.readFile(filepath, "utf8", (err, data) => {
        if (err) {
            res.writeHead(500, {"Content-Type": "text/plain"});
            res.end("Error reading file.");
        }
        else {
            res.writeHead(200, {"Content-Type": "text/plain"});
            res.end(data);
        };
    });
});

server.listen(config.port, () => {
    console.log(config.app);
    console.log("Port: ", config.port)

    console.log("");

    console.log("Heap Size Limit: ", (heapStats.heap_size_limit / 1024 / 1024), "MB");
    console.log("Used Heap Size: ", (heapStats.used_heap_size / 1024 / 1024), "MB");
    console.log("Total Heap Size: ", (heapStats.total_heap_size / 1024 / 1024), "MB");
});