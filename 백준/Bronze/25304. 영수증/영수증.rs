use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let total_price = input.next().unwrap();
    let total_cnt = input.next().unwrap();
    let mut sum = 0;
    for _ in 0..total_cnt {
        let price = input.next().unwrap();
        let cnt = input.next().unwrap();
        sum += price * cnt;
    }
    println!("{}", if total_price == sum { "Yes" } else { "No" })
}
