use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let k = it.next().unwrap();
    let mut a = 0;
    let mut b = 1;
    for _ in 1..k {
        (a, b) = (b, a + b);
    }
    print!("{a} {b}");
}