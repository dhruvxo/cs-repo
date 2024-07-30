//define a tuple of coords representing latitude and longitude. print each element seperately
fn main(){
    let coords:(f32,f32) = (10.5,32.5);
    println!("Longitude: {}",coords.0);
    println!("Latitude: {}",coords.1);
}