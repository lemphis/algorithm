use std::{
    collections::HashSet,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n = f().parse::<usize>().unwrap();
    let mut set = HashSet::new();
    for _ in 0..n {
        let mut is_duplicate = false;
        let s = f();
        for i in 0..s.len() {
            if set.contains(&s.repeat(2)[i..i + s.len()]) {
                is_duplicate = true;
                break;
            }
        }
        if !is_duplicate {
            set.insert(s);
        }
    }

    print!("{}", set.len());
}