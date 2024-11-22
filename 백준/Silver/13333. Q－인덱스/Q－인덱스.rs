use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut counts = input.take(n).collect::<Vec<_>>();
    counts.sort_unstable();
    for k in (1..=n).rev() {
        if counts[n - k] >= k {
            print!("{k}");
            return;
        }
    }
    print!("0")
}