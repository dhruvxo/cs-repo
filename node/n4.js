const buf1=Buffer.alloc(7,'Hi I am') //number is buffer size
const buf2=Buffer.alloc(5,'Dhruv');

console.log("Buffer1",buf1.toString());
console.log("Buffer2",buf2.toString());

const totallength=buf1.length+buf2.length;
console.log(totallength);

const buf3=Buffer.concat([buf1,buf2]);
console.log(buf3.toString()); //toString converts ascii values to string
console.log(buf3.length);

var buf = Buffer.from('PES University');
buf.write('Bengaluru',5);
console.log(buf.toString());