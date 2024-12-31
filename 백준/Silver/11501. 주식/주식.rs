use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for _ in 0..t {
        let n = f();
        let prices = (0..n).map(|_| f()).collect::<Vec<_>>();
        let (mut revenue, mut max) = (0, *prices.last().unwrap());
        for &price in prices.iter().rev().skip(1) {
            if price > max {
                max = price;
            } else {
                revenue += max - price;
            }
        }
        output.push_str(&format!("{revenue}\n"));
    }
    print!("{output}");
}