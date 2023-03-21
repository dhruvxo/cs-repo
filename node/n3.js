const mylib=require('./mylib.js')

console.log(mylib.constant)
console.log("addition of 6 and 9 = ", +mylib.myadd(6,9))
console.log("difference of 6 and 9",+mylib.mysub(6,9))
console.log("product of 6 and 9",+mylib.mymul(6,9))
console.log("quotient of 6 and 9",+mylib.mydiv(6,9))