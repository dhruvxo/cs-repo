var url=require('url');
var http=require('http');
var fs=require('fs');

http.createServer(function(request,response){
    response.writeHead(200,{'Content-type':'text/plain'});
    response.end("WELCOME TO WEB SERVER");
}).listen(8080);

console.log("Server is Up and running On http://localhost:8080");