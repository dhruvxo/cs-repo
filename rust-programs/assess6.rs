use std::io;

fn main() {
    let mut rolls = String::new();
    io::stdin().read_line(&mut rolls).expect("Failed to read line");
    let rollsint: i32 = rolls.trim().parse().unwrap();
    
    for _ in 0..rollsint {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let concatenated = format!("{}", &input[0..1]);
        let concatenated_int: i32 = concatenated.trim().parse().unwrap();
        let concatenated2 = format!("{}", &input[2..3]);
        let concatenated2_int: i32 = concatenated2.trim().parse().unwrap();
        let concatenatedtotal = concatenated_int + concatenated2_int;
        
        if concatenatedtotal > 6 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
