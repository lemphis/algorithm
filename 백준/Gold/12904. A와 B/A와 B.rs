use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let (s, mut t) = {
        let mut it = input.split_whitespace();
        (
            it.next().unwrap().to_string(),
            it.next().unwrap().to_string(),
        )
    };
    loop {
        if t.ends_with('A') {
            t.pop();
        } else {
            t.pop();
            t = t.chars().rev().collect();
        }
        if s.len() == t.len() {
            print!("{}", if s == t { 1 } else { 0 });
            break;
        }
    }
}