use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut input = || input.next().unwrap();
    let (n, m) = (input(), input());
    let mut prices = (0..m).map(|_| input()).collect::<Vec<_>>();
    prices.sort_unstable();
    let (mut min_price, mut max_total_price) = (0, 0);
    for (i, &price) in prices.iter().rev().enumerate().take(n) {
        let total_price = price * (i + 1);
        if total_price > max_total_price {
            min_price = price;
            max_total_price = total_price;
        }
    }
    print!("{} {}", min_price, max_total_price);
}