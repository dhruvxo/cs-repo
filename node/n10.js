var express = require('express');
var app = express();

app.get('/',function(req,res){
    res.send('<h1>Hello Earth</h1>');
});

app.get('/tst',function(req,res){
    res.send('<h1>Hello Earth</h1>');
});

app.listen(6969, function() {
    console.log("server running");
});