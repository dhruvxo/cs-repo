fn is_palindrome(s: &str) -> bool {
    let chars: Vec<char> = s.chars().collect();
    let len = chars.len();
    for i in 0..len / 2 {
        if chars[i] != chars[len - 1 - i] {
            return false;
        }
    }
    true
}

fn main() {
    let test_str = "racecar";
    println!("Is '{}' a palindrome? {}", test_str, is_palindrome(test_str));
}
