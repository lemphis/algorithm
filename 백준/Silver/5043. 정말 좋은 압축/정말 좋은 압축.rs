use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(64);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, b) = (f(), f());

    let mut sum = 1;
    for i in 1..=b {
        sum += 1 << i;
    }

    print!("{}", if sum >= n { "yes" } else { "no" });
}