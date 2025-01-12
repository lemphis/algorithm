use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut levels = (0..n).map(|_| f()).collect::<Vec<_>>();
    levels.sort_unstable();
    let pop = levels.pop().unwrap();
    print!("{}", levels.iter().fold(0, |acc, cur| acc + cur + pop));
}