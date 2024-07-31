use std::collections::HashSet;

fn perform_set_operation(
    set1: &HashSet<i32>,
    set2: &HashSet<i32>,
    operation: char,
) -> HashSet<i32> {
    let mut result = HashSet::new();
    match operation {
        'u' => {
            for &item in set1 {
                result.insert(item);
            }
            for &item in set2 {
                result.insert(item);
            }
        }
        'i' => {
            for &item in set1 {
                if set2.contains(&item) {
                    result.insert(item);
                }
            }
        }
        'd' => {
            for &item in set1 {
                if !set2.contains(&item) {
                    result.insert(item);
                }
            }
        }
        's' => {
            for &item in set1 {
                if !set2.contains(&item) {
                    result.insert(item);
                }
            }
            for &item in set2 {
                if !set1.contains(&item) {
                    result.insert(item);
                }
            }
        }
        _ => {}
    }
    return result
}
fn main() {
    let set1: HashSet<i32> = vec![1, 2, 3].into_iter().collect();
    let set2: HashSet<i32> = vec![3, 4, 5].into_iter().collect();

    println!("Union: {:?}", perform_set_operation(&set1, &set2, 'u'));
    println!("Intersection: {:?}", perform_set_operation(&set1, &set2, 'i'));
    println!("Difference: {:?}", perform_set_operation(&set1, &set2, 'd'));
    println!("Symmetric Difference: {:?}", perform_set_operation(&set1, &set2, 's'));
}
