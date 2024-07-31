//Define a function named 'calculate_rectangle_area' that takes width and height as parameters and returns the calculate_rectangle_area
fn main(){
    println!("area is {}",calculate_rectangle_area(5,4))
}

fn calculate_rectangle_area(height:i32,width:i32)->i32{
    height * width
}