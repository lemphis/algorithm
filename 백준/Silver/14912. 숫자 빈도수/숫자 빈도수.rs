use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<u32>);
    let (n, d) = (input.next().unwrap(), input.next().unwrap());
    print!(
        "{}",
        (1..=n)
            .map(|i| i
                .to_string()
                .chars()
                .filter(|&c| c == char::from_digit(d, 10).unwrap())
                .collect::<Vec<_>>())
            .fold(0, |mut acc, cur| {
                acc += cur.len();
                acc
            })
    );
}