use std::{io, collections::HashSet};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let _ = input.next().unwrap().parse::<i32>().unwrap();
    let game = input.next().unwrap();
    let set = input.collect::<HashSet<_>>();
    let count = match game {
        "Y" => set.len(),
        "F" => set.len() / 2,
        "O" => set.len() / 3,
        _ => unreachable!()
    };
    print!("{count}");
}