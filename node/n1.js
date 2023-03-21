// console.log("Hello World")

// const name1="Dhruv"
// console.log("Hello",name1)

const fs=require('fs')
fs.readFile("randomfile.js", function(err,data){
    if(err)
    {
        console.log(err)
    }
    setTimeout(()=>{
        console.log("PES University display after 2 seconds")
    },2000)
})
console.log("Starts here")

// setTimeout(()=>{
//     console.log("Timer Stopped")},2000)
//     console.log("Timer Started")