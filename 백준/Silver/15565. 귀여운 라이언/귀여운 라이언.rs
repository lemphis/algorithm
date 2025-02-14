use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let mut poses = Vec::new();
    for i in 0..n {
        if f() == 1 {
            poses.push(i as i32);
        }
    }
    print!(
        "{}",
        poses
            .windows(k)
            .map(|w| w.last().unwrap() - w.first().unwrap() + 1)
            .min()
            .unwrap_or(-1)
    );
}