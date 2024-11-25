use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let prices = input.take(n).collect::<Vec<_>>();
    let (mut min, mut max_diff) = (prices[0], 0);
    for &price in prices.iter().skip(1) {
        if price < min {
            min = price;
        } else {
            max_diff = max_diff.max(price - min);
        }
    }
    print!("{max_diff}");
}