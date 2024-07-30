fn main() {
    const SECRET_MESSAGE: &str = "HELLO";
    const KEY: i32 = 3;

    let mut modified_message = String::new();

    for c in SECRET_MESSAGE.chars() {
        let modified_char = ((c as u8 as i32 + KEY) as u8) as char;
        modified_message.push(modified_char);
    }

    println!("Modified message: {}", modified_message);
}
