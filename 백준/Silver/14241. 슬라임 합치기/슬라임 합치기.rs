use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut slimes = (0..n).map(|_| f()).collect::<Vec<_>>();
    slimes.sort_by(|a, b| b.cmp(a));
    let mut sum = 0;
    while slimes.len() > 1 {
        let (a, b) = (slimes.pop().unwrap(), slimes.pop().unwrap());
        sum += a * b;
        slimes.push(a + b);
    }
    print!("{sum}");
}