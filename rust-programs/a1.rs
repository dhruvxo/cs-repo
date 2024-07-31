//Define a function named 'fibonacci' that takes a non negative integer 'n' as input and returns the nth Fibonacci number.
use std::io;

fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let mut convert = input.trim().split_whitespace();
    let fibb: i32 = convert.next().unwrap().parse().expect("Please enter a valid number");

    let fib = fibonacci(fibb);
    println!("Fibonacci number from series is {}",fib)
}

fn fibonacci(n:i32)->i32{
    if n==1{
        return 1
    }
    else if n==0{
        return 0
    }
fibonacci(n-1)+fibonacci(n-2)   
}