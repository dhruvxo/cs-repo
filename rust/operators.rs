fn main(){
    let num1=10;
    let num2=2;
    let mut res:i32;

    //Arithmetic
    res=num1%num2;
    println!("Remainder:{}",res);

    //Logical
    if(a>10)&&(b>10){
        println!("true");
    }

    //Relational
    let A:i32=2; //10
    let B:i32=3; //11
    let mut res=A>B;
    println!("A greater than B:{}",res);

    //Bitwise
    let mut res:i32;
    res=a^b;
    println!("(a^b)=>{}",res);
}