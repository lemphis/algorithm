use std::{
    collections::HashMap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let mut map = HashMap::new();
    map.insert("ChongChong", true);
    let n = input.next().unwrap().parse::<usize>().unwrap();
    for _ in 0..n {
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        if map.contains_key(a) || map.contains_key(b) {
            map.insert(a, true);
            map.insert(b, true);
        }
    }
    print!("{}", map.len());
}