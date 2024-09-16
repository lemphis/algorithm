use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i64>);
    let n = input.next().unwrap();
    print!("{}", input.sum::<i64>() - (n * (n - 1) / 2));
}