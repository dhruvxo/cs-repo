var val=require('validator')

var name='dhruv'
console.log(val.isLowercase(name))
name='dhruv'
console.log(val.isLowercase(name))

var email='xyz@pes.edu'
console.log(val.isEmail(email))
email='xyz@.edu'
console.log(val.isEmail(email))