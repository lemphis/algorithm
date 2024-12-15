use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let mut weights = (0..n).map(|_| f()).collect::<Vec<_>>();
    weights.sort_unstable();
    let (mut l, mut r, mut count) = (0, n - 1, 0);
    while l < r {
        if weights[l] + weights[r] <= k {
            count += 1;
            l += 1;
            r -= 1;
        } else {
            r -= 1;
        }
    }
    print!("{count}");
}