use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let (n, m) = {
        let mut it = input.split_whitespace().map(|x| x.parse::<u128>().unwrap());
        (it.next().unwrap(), it.next().unwrap())
    };
    println!("{}", (1..=m).fold(1, |acc, val| acc * (n - val + 1) / val));
}