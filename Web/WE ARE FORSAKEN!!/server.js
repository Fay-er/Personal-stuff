// import http from 'http';
import express from 'express';
// import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';
import config from './config.js';

const __fileDirectory = fileURLToPath(import.meta.url);
const __dirName = path.dirname(__fileDirectory);
const app = express();

app.use(express.static(path.join(__dirName, 'public')));

app.listen(config.port, () => {
    console.log(config.app);
    console.log("Port: ", config.port);
});