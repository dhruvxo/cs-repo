fn main(){
    let cmd_line=std::env::args();
    println!("No.of elements in arguments is {}",cmd_line.len());
    for arg in cmd_line{
        println!("[{}]",arg);
    }
}