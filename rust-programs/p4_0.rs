//Write a rust program for 6 students with 3 courses each. For each course how much grades they got by defining an enum function. Count the students, grade wise.
#[derive(Debug)]
enum Grade {
    A,
    B,
    C,
    D,
    F,
}

struct Course {
    name: String,
    grade: Grade,
}

struct Student {
    name: String,
    courses: Vec<Course>,
}

fn main() {
    // Create a list of students with their courses and grades
    let students = vec![
        Student {
            name: String::from("Student 1"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::A },
                Course { name: String::from("Science"), grade: Grade::B },
                Course { name: String::from("History"), grade: Grade::C },
            ],
        },
        Student {
            name: String::from("Student 2"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::B },
                Course { name: String::from("Science"), grade: Grade::A },
                Course { name: String::from("History"), grade: Grade::B },
            ],
        },
        Student {
            name: String::from("Student 3"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::D },
                Course { name: String::from("Science"), grade: Grade::C },
                Course { name: String::from("History"), grade: Grade::A },
            ],
        },
        Student {
            name: String::from("Student 4"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::B },
                Course { name: String::from("Science"), grade: Grade::A },
                Course { name: String::from("History"), grade: Grade::D },
            ],
        },
        Student {
            name: String::from("Student 5"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::F },
                Course { name: String::from("Science"), grade: Grade::F },
                Course { name: String::from("History"), grade: Grade::C },
            ],
        },
        Student {
            name: String::from("Student 6"),
            courses: vec![
                Course { name: String::from("Math"), grade: Grade::A },
                Course { name: String::from("Science"), grade: Grade::B },
                Course { name: String::from("History"), grade: Grade::C },
            ],
        },
    ];

    let mut grade_a = 0;
    let mut grade_b = 0;
    let mut grade_c = 0;
    let mut grade_d = 0;
    let mut grade_f = 0;

    for student in &students {
        println!("Student: {}", student.name);
        for course in &student.courses {
            println!("  Course: {}, Grade: {:?}", course.name, course.grade);
            match course.grade {
                Grade::A => grade_a += 1,
                Grade::B => grade_b += 1,
                Grade::C => grade_c += 1,
                Grade::D => grade_d += 1,
                Grade::F => grade_f += 1,
            }
        }
    }

    println!("\nGrade A: {}", grade_a);
    println!("Grade B: {}", grade_b);
    println!("Grade C: {}", grade_c);
    println!("Grade D: {}", grade_d);
    println!("Grade F: {}", grade_f);
}
