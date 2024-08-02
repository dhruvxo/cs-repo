fn main(){
    let mut v = Vec::new();
    v.push(20);
    v.push(30);
    v.push(40);
    println!("{:?}",v);
    v.remove(1);
    println!("{:?}",v);
    if v.contains(&2){
        println!("{:?}",v);
    }
}