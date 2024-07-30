//write a rust program to perform match operation
fn main(){
    const STATE_CODE:&str="MH";
    let state = match STATE_CODE {
    "MH" => {println!("Found match to MH");"Maharashtra"},
    "KL" => "Kerala",
    _ => "Unknown"
};
    println!("state name is {}",state)
}