use std::io;

fn main() {
    // Read input values
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    
    // Split the input into two parts and parse them as integers
    let parts: Vec<i32> = input.trim().split_whitespace()
                                .map(|s| s.parse().expect("Parse error"))
                                .collect();
    
    let x = parts[0]; // Threshold limit
    let y = parts[1]; // Current brain speed
    
    // Check if Chef is prone to errors
    if y > x {
        println!("YES");
    } else {
        println!("NO");
    }
}
