fn main() {
    const STRING: &str = "Hello";
    const REPETITIONS: usize = 3;
    let mut repeated_string = String::new();

    for i in 0..REPETITIONS {
        repeated_string.push_str(STRING);
    }
    println!("{}", repeated_string);
}