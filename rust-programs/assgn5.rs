fn main(){
    let message1: &str = "Good";
    let message2: &str = "Morning";
    const SEPERATOR: usize =  5;
    let seperator_chars = "|".repeat(SEPERATOR);
    println!("{}{}{}",message1,seperator_chars,message2);
}