use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let (mut max, mut sum) = (0, 0);
    for _ in 0..n {
        let snow = f();
        sum += snow;
        max = max.max(snow);
    }
    let ans = max.max((sum + 1) / 2);
    if ans > 1440 {
        print!("-1");
        return;
    }
    print!("{ans}");
}