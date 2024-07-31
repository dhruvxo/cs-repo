use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let test_cases: i32 = input.trim().parse().expect("Please enter a number");

    for _ in 0..test_cases {
        let mut x_input = String::new();
        io::stdin().read_line(&mut x_input).expect("Failed to read line");
        let x: i32 = x_input.trim().parse().expect("Please enter a number");

        if x >= 2000 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
