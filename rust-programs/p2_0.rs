fn main() {
    let numbers: [i32; 5] = [1, -2, 3, -4, 5]; 

    let mut sum_positive = 0;
    let mut product_negative = 1;
    let mut has_negative = false;

    for num in numbers {
        if num > 0 {
            sum_positive += num;
        } else if num < 0 {
            product_negative *= num;
            has_negative = true;
        }
    }

    println!("Sum of positive numbers: {}", sum_positive);
    if has_negative {
        println!("Product of negative numbers: {}", product_negative);
    } else {
        println!("No negative numbers in the array.");
    }
}
