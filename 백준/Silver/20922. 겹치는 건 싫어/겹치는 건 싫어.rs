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
    let (mut l, mut r, mut max_len) = (0, 0, 0);
    while r < n {
        if let Some(count) = map.get(&nums[r]) {
            if *count == k {
                loop {
                    let num = map.get_mut(&nums[l]).unwrap();
                    *num -= 1;
                    l += 1;
                    if nums[l - 1] == nums[r] {
                        break;
                    }
                }
            }
        }
        *map.entry(nums[r]).or_insert(0) += 1;
        r += 1;
        max_len = max_len.max(r - l);
    }
    print!("{max_len}");
}