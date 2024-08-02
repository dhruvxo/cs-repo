use std::collections::HashSet;

fn main(){
    let mut states = HashSet::new();
    states.insert("KA");
    states.insert("KL");
    states.insert("JK");
    if states.contains("KL"){
        println!("Kerala is found");
    }
    println!("States = {:?}",states);
    states.remove("JK");
    println!("No. of states = {:?}",states.len());   
}