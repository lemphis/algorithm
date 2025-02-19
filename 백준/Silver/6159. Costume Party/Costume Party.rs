use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, s) = (f(), f());
    let mut cows: Vec<usize> = (0..n).map(|_| f()).collect();
    cows.sort_unstable();
    let mut count = 0;
    for l in 0..n - 1 {
        for r in l + 1..n {
            if cows[l] + cows[r] > s {
                break;
            }
            count += 1;
        }
    }
    print!("{count}");
}