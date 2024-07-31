fn main(){
    let b:(i32,bool,f64) = (30,true,7.9);
    display(b);
}
fn display(x:(i32,bool,f64)){
    println!("Inside print method");
    let (age,is_male,cgpa) = x;
    println!("Age is {}, Is he male? {}, CGPA is {}",age,is_male,cgpa)
}
