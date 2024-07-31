//write a rust program to perform match operation
fn main(){
    const STATE_CODE:&str="KA";
    let state = match STATE_CODE {
    "KA" => {println!("Found match to KA");"Karnataka"},
    "KL" => "Kerala",
    _ => "Unknown"
};
    println!("state name is {}",state)
}