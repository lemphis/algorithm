use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let kettles: Vec<usize> = (0..n).map(|_| f()).collect();
    let (mut l, mut r) = (0, i32::MAX as usize);
    while l + 1 < r {
        let mid = (l + r) / 2;
        (l, r) = match check(&kettles, k, mid) {
            true => (mid, r),
            false => (l, mid),
        }
    }
    print!("{l}");
}

fn check(kettles: &[usize], k: usize, mid: usize) -> bool {
    kettles.iter().map(|ml| ml / mid).sum::<usize>() >= k
}