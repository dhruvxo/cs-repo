use std::io::Write;
fn main(){
    let b1= std::io::stdout().write("PES".as_bytes()).unwrap();
    let b2= std::io::stdout().write(String::from("University").as_bytes()).unwrap();
    std::io::stdout().write(format!("\n Bytes written {}",(b1+b2)).as_bytes()).unwrap();
}