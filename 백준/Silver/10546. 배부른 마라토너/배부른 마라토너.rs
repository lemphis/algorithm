use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();
    let mut map = HashMap::with_capacity(n);
    for _ in 0..n {
        let name = f();
        *map.entry(name).or_insert(0) += 1;
    }
    for _ in 0..n - 1 {
        let name = f();
        if let Some(count) = map.get_mut(name) {
            *count -= 1;
        }
    }
    print!(
        "{}",
        map.into_iter().find(|&(_, count)| count > 0).unwrap().0
    );
}