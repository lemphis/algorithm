use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap() as usize;
    println!("{}", (0..n).map(|_| input.next().unwrap() * input.next().unwrap()).fold(0, |acc, cur| acc + cur));
}