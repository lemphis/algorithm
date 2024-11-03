use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, l) = (f(), f());
    let mut poses = (0..n).map(|_| f()).collect::<Vec<_>>();
    poses.sort_unstable();
    let poses = poses.iter().map(|&pos| pos as f64).collect::<Vec<_>>();
    let (mut right, mut count) = (poses[0] + l as f64 - 0.5, 1);
    for &pos in poses.iter() {
        if pos > right {
            right = pos + l as f64 - 0.5;
            count += 1;
        }
    }
    print!("{count}");
}