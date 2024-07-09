use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let num = input.next().unwrap();
    let count = input.next().unwrap();
    print!(
        "{}",
        match num {
            1 => count * 8,
            2..=4 => 4 * count + if count & 1 == 0 { num - 1 } else { 5 - num },
            5 => count * 8 + 4,
            _ => unreachable!(),
        }
    );
}