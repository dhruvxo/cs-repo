use std::collections::HashMap;

fn main() {
    let tuples = vec![
        ("even", 2),
        ("odd", 3),
        ("even", 4),
        ("odd", 5),
    ];

    let mut map: HashMap<&str, Vec<i32>> = HashMap::new();

    for (key, value) in tuples {
        if !map.contains_key(key) {
            map.insert(key, Vec::new());
        }
        map.get_mut(key).unwrap().push(value);
    }

    for (key, values) in &map {
        println!("{}: {:?}", key, values);
    }
}
