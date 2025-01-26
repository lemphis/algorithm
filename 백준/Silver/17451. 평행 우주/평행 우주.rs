use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let speeds: Vec<usize> = (0..n).map(|_| f()).collect();
    let mut ans = *speeds.last().unwrap();
    for &speed in speeds.iter().rev().skip(1) {
        if speed > ans {
            ans = speed;
        } else {
            if ans % speed > 0 {
                ans = ((ans / speed) + 1) * speed;
            }
        }
    }
    print!("{ans}");
}