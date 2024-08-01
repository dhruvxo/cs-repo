//Perform slice operations on the following: A1 = 2 3 4 5 and A2 = 6 7 8 9. Add odd index. Multiply even index values.
fn main() {
        let a1 = [2, 3, 4, 5];
        let a2 = [6, 7, 8, 9];
    
        let sum_odd_indices: i32 = a1.iter().enumerate()
            .filter(|&(i, _)| i % 2 != 0)
            .map(|(_, &val)| val)
            .sum::<i32>() + a2.iter().enumerate()
            .filter(|&(i, _)| i % 2 != 0)
            .map(|(_, &val)| val)
            .sum::<i32>();
    
        let product_even_indices: i32 = a1.iter().enumerate()
            .filter(|&(i, _)| i % 2 == 0)
            .map(|(_, &val)| val)
            .product::<i32>() * a2.iter().enumerate()
            .filter(|&(i, _)| i % 2 == 0)
            .map(|(_, &val)| val)
            .product::<i32>();
    
        println!("Sum of odd indices: {}", sum_odd_indices);
        println!("Product of even indices: {}", product_even_indices);
    }
    