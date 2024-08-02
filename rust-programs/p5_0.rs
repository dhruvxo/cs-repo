//Addition of 4 numbers using command line arguments
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 5 {
        println!("Usage: {} <num1> <num2> <num3> <num4>", args[0]);
        std::process::exit(1);
    }

    let num1: f64 = args[1].parse().expect("Invalid number");
    let num2: f64 = args[2].parse().expect("Invalid number");
    let num3: f64 = args[3].parse().expect("Invalid number");
    let num4: f64 = args[4].parse().expect("Invalid number");

    let sum = num1 + num2 + num3 + num4;

    println!("Sum of {} + {} + {} + {} = {}", num1, num2, num3, num4, sum);
}