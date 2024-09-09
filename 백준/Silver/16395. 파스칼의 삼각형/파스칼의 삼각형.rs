use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let (n, k) = (input.next().unwrap(), input.next().unwrap());
    print!("{}", combination(n - 1, k - 1));
}

fn combination(n: usize, k: usize) -> usize {
    if k == 0 || n == k {
        return 1;
    }
    let f = |acc, cur: usize| acc * cur;
    let max = k.max(n - k);
    (max + 1..=n).fold(1, f) / (2..=n - max).fold(1, f)
}