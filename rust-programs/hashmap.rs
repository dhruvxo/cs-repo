use std::collections::HashMap;

fn main(){
    let mut states = HashMap::new();
    states.insert("KA","Karnataka");
    states.insert("KL","Kerala");
    states.insert("JK","JammuKashmir");
    states.remove("JK");
    if states.contains_key("KL"){
        println!("Kerala is found");
    }
    println!("States = {:?}",states);
    println!("No. of states = {:?}",states.len());   
}