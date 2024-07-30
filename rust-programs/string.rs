fn main(){
//     let company:&'static str="INFOSYS";
//     let location:&'static str="Hyderabad";
//     println!("company is:'{}' and is located at '{}'",company,location);

//     let empty_string = String::new();
//     println!("length is {}",empty_string.len());

//     let content_string=String::from("INFOSYS");
//     println!("length is {}",content_string.len());

//     let mut z=String::new();
//     z.push_str("hello");
//     println!("{}",z);

//     let name1="Hello PES University, Hello!".to_string();
//     println!("{}",name1);
//     let _name2 = name1.replace("Hello","Welcome"); //find and replace
//     println!("{}",_name2);
// //creating functions by pushing
//     let example_string=String::from("example_string");
//     print_literal(example_string.as_str());

// //trim
// let fullname="PES University\r\n";

// println!("Before Trim");
// println!("Length is {}",fullname.len());
// println!();
// println!("After trim");
// println!("length is {}",fullname.trim().len());
// //split
// let mut i=1;
// for token in name1.split_whitespace()
// {
//     println!("token {} : {}",i,token);
//     i+=1;
// }

let n1="PES".to_string();
let n2="University".to_string();
// let n3=n1 + &n2;
let n3=format!("{} {}",n1,n2);
println!("{}",n3);

// for n in n1.chars(){
//     println!("{}",n);
// }
}

// fn print_literal(data:&str)
// {
//     println!("displaying string literal {}", data);
// }

