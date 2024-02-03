use std::io;


fn main() {

    let mut x = String::new();

    io::stdin().read_line(&mut x).expect("Failed to read line");

    let a: i32 = x.trim().parse().expect("Invalid input");


    println!("{}", a);

}