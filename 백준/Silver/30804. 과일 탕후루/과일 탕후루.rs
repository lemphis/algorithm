use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let fruits: Vec<usize> = (0..n).map(|_| f()).collect();

    let mut map = HashMap::new();
    let (mut l, mut max_len) = (0, 0);
    for r in 0..n {
        *map.entry(&fruits[r]).or_insert(0) += 1;
        while map.len() > 2 {
            *map.get_mut(&fruits[l]).unwrap() -= 1;
            if *map.get(&fruits[l]).unwrap() == 0 {
                map.remove(&fruits[l]);
            }
            l += 1;
        }
        max_len = max_len.max(r - l + 1);
    }

    print!("{max_len}");
}