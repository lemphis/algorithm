use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let input = input.split_ascii_whitespace().flat_map(str::parse::<u128>);
    let mut sum = 0;
    for num in input {
        sum += num;
    }
    println!("{}", sum)
}
