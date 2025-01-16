use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k, b) = (f(), f(), f());
    let mut blinkers = vec![true; n];
    for _ in 0..b {
        blinkers[f() - 1] = false;
    }
    let mut count = blinkers.iter().take(k).filter(|&b| !b).count();
    let mut min_count = count;
    for i in k..n {
        if !blinkers[i] {
            count += 1;
        }
        if !blinkers[i - k] {
            count -= 1;
        }
        min_count = min_count.min(count);
    }
    print!("{min_count}");
}