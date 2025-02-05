use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();
    let mut map = HashMap::new();
    for _ in 0..n {
        let mut cows = [f(), f(), f()];
        cows.sort_unstable();
        *map.entry(cows).or_insert(0) += 1;
    }
    print!("{}", map.iter().max_by_key(|(_, v)| *v).unwrap().1);
}