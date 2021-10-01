const fs = require('fs');
const http = require('http');
const path = require('path');
const req = require('path');

const hostname = 'localhost';
const port = 3000;

const server = http.createServer((req,res) => {
    console.log("Request for " + req.url + " Method "+req.method);

    if(req.method=='GET')
    {
        var fileurl;
        if( req.url == '/') fileurl = '/index.html';
        else fileurl = req.url;

        var filePath = path.resolve('./public'+fileurl);
        const fileExt = path.extname(filePath);
        res.setHeader('Content-type', 'text/html');
        if(fileExt == '.html')
        fs.exists(filePath, (exists) =>{
            if(!exists){
                res.statusCode = 404;
                res.end('<html><body><h1>Error 404: ' + fileUrl + 
                ' not found</h1></body></html>');
                return;
            }
            res.statusCode = 200;
            fs.createReadStream(filePath).pipe(res);
        });
    }
    else {
        res.statusCode = 404;
        res.statusCode = 404;
        res.end('<html><body><h1>Error 404: ' + req.method + 
                ' not supported</h1></body></html>');
    }

})

server.listen(port, hostname, () =>{
    console.log(`Server running at http://${hostname}:${port}`);
})

//result componenets are : Header , statusCode , createreadstream , end