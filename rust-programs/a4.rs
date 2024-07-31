//WAP that takes an array of integers as input and returns the sum of all elements. Use functions.
fn main() {
    let numbers = [1, 2, 3, 4, 5];
    let sum = sum_array(&numbers);
    println!("The sum of the array elements is: {}", sum);
}

fn sum_array(arr: &[i32]) -> i32 {
    let mut sum = 0;
    for &num in arr.iter() {
        sum += num;
    }
    return sum
}
