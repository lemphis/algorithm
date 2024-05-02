use std::io;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut input = input.trim().split(':');
    let a = input.next().unwrap().parse::<usize>().unwrap();
    let b = input.next().unwrap().parse::<usize>().unwrap();
    let gcd = gcd(a, b);
    print!("{}:{}", a / gcd, b / gcd);
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}