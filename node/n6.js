var fs=require('fs')
var abc='';

var rs=fs.createReadStream('data.txt');
rs.setEncoding('UTF-8');
rs.on('data',function(chunk){
    abc+=chunk;
})
rs.on('end',function(chunk){
    console.log(abc);
})
rs.on('err',(chunk)=>{
    console.log(err.stack);
})