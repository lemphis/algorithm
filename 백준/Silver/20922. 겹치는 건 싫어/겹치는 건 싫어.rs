use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let nums: Vec<usize> = (0..n).map(|_| f()).collect();

    let mut map = HashMap::new();
    let (mut l, mut max_len) = (0, 0);
    for r in 0..n {
        let num = map.entry(nums[r]).or_insert(0);
        *num += 1;
        while *map.get(&nums[r]).unwrap() > k {
            *map.get_mut(&nums[l]).unwrap() -= 1;
            l += 1;
        }
        max_len = max_len.max(r - l + 1);
    }
    print!("{max_len}");
}