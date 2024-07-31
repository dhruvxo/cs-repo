//Define a function that takes a number 'n' as input and prints the Fibonacci equence up to 'n' terms
use std::io;

fn fibonacci(n: i32) {
    let mut a = 0;
    let mut b = 1;

    for _i in 0..n {
        print!("{} ", a);
        let temp = a;
        a = b;
        b = temp + b;
    }
    println!();
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let mut convert = input.trim().split_whitespace();
    let n: i32 = convert.next().unwrap().parse().expect("Please enter a valid number");
    print!("Fibonacci series is ");
    fibonacci(n);
}
