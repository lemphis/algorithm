use std::{io, collections::HashSet};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap() as usize;
    let mut set = HashSet::new();
    for _ in 0..n {
        let num = input.next().unwrap();
        if set.contains(&num) {
            print!("{num}");
            return;
        }
        set.insert(num);
    }
}