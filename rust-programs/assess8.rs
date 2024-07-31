use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");

    let mut parts = input.trim().split_whitespace();
    let x: i32 = parts.next().unwrap().parse().expect("Please enter a valid number");
    let y: i32 = parts.next().unwrap().parse().expect("Please enter a valid number");

    if x >= 2 * y {
        println!("Yes");
    } else {
        println!("No");
    }
}
