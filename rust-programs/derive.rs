// #[derive(Debug)]
// enum GenderCategory {
//     Male,Female
// }
// #[derive(Debug)]
// struct Person {
//     name: String,
//     gender: GenderCategory
// }
// fn main(){
//     let p1=Person{
//         name:String::from("Dhruv"),
//         gender:GenderCategory::Male
//     };
//     let p2=Person{
//         name:String::from("Amy"),
//         gender:GenderCategory::Female
//     };
//     println!("{},{:?}",p1.name,p1.gender);
//     println!("{},{:?}",p2.name,p2.gender);
// }

#[derive(Debug)]
enum CarType{
    Match,
    Sedan,
    SUV
}
fn print_size(car:CarType){
    match car{
        CarType::Match => println!("Small car"),
        CarType::Sedan => println!("Medium car"),
        CarType::SUV => println!("Large car")
    }
}
fn main(){
    print_size(CarType::Match);
    print_size(CarType::Sedan);
    print_size(CarType::SUV);
}