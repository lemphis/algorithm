use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let mut poses = (0..n).map(|_| (f(), f())).collect::<Vec<_>>();
    poses.sort_unstable();
    let (mut max, mut len) = (i32::MIN, 0);
    for &(x, y) in poses.iter() {
        if x > max {
            max = y;
            len += max - x;
        } else if y > max {
            len += y - max;
            max = y;
        }
    }
    print!("{len}");
}