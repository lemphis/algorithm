use std::{
    collections::HashSet,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: HashSet<usize> = (0..n).map(|_| f()).collect();
    let mut min_count = 4;
    for num in nums.iter() {
        let mut count = 4;
        for i in 1..5 {
            if nums.contains(&(num + i)) {
                count -= 1;
            }
        }
        min_count = min_count.min(count);
    }

    print!("{min_count}");
}