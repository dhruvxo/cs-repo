//Read CSV/Excel file which has 4 rows and 4 columns. Display result in tabular form
use std::fs::File;
use std::io::{BufReader, BufRead};

fn main() {
    let file_path = "data.csv";

    if let Ok(file) = File::open(file_path) {
        let reader = BufReader::new(file);
        for line in reader.lines() {
            if let Ok(record) = line {
                let fields: Vec<&str> = record.split(',').collect();
                for field in fields {
                    print!("{:<15}", field);
                }
                println!();
            }
        }
    } else {
        println!("Error opening file.");
    }
}