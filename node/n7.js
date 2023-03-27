var fs=require('fs')
var data="This has been overwritten"
var ws=fs.createWriteStream('overwrite.txt');
ws.write(data,'UTF-8');
ws.end();
ws.on('finish',function(){
    console.log('Write Completed');
})
ws.on('error',function(){
    console.log(error.stack);
})
    console.log('Program Ended')
    