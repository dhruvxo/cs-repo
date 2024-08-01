//Write a Rust program that implements an enum Shape with variants representing different geometric shapes (e.g. Circle, Triangle, Square)
#[derive(Debug)]

enum Shape {
    Circle { radius: f64 },
    Triangle { base: f64, height: f64 },
    Square { length: f64 },
}

fn main() {
    let circle = Shape::Circle { radius: 5.0 };
    let triangle = Shape::Triangle { base: 3.0, height: 4.0 };
    let square = Shape::Square { length: 2.5 };

    println!("Circle: {:?}", circle);
    println!("Triangle: {:?}", triangle);
    println!("Square: {:?}", square);
}
