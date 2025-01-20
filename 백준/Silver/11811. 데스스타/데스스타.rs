use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let matrix: Vec<Vec<usize>> = (0..n).map(|_| (0..n).map(|_| f()).collect()).collect();
    let ans = matrix
        .iter()
        .map(|r| r.iter().max().unwrap().to_string())
        .collect::<Vec<String>>()
        .join(" ");
    print!("{ans}");
}