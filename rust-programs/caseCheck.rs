fn check_case(s: &str) -> &str {
    if s.chars().all(|c| c.is_uppercase()) {
        "Uppercase characters!"
    } else if s.chars().all(|c| c.is_lowercase()) {
        "Lowercase characters!"
    } else {
        "Mixed case characters!"
    }
}

fn main() {
    let upper = "HELLO";
    let lower = "hello";
    let mixed = "Hello";

    println!("{}", check_case(upper)); // Uppercase characters
    println!("{}", check_case(lower)); // Lowercase characters
    println!("{}", check_case(mixed)); // Mixed case characters
}
