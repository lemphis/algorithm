use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut poses = input.skip(1).collect::<Vec<_>>();
    poses.sort_unstable();
    let mut idx = poses.len() / 2;
    if poses.len() & 1 == 0 {
        idx -= 1;
    }
    print!("{}", poses[idx]);
}