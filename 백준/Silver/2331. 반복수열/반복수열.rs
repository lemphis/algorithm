use std::{collections::HashMap, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let (mut a, p) = (input.next().unwrap(), input.next().unwrap());
    let mut map = HashMap::new();
    map.insert(a, 1);
    loop {
        let mut sum = 0;
        while a > 0 {
            let remainder = a % 10;
            sum += remainder.pow(p as u32);
            a /= 10;
        }
        a = sum;
        *map.entry(sum).or_insert(0) += 1;
        if map[&sum] == 3 {
            break;
        }
    }
    print!(
        "{}",
        map.iter()
            .fold(0, |acc, (_, &value)| acc + if value == 1 { 1 } else { 0 })
    );
}