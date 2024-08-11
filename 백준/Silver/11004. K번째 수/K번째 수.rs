use std::io::{self};

fn main() {
    let input = io::read_to_string(io::stdin()).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<i32>);
    let (n, k) = (it.next().unwrap() as usize, it.next().unwrap() as usize);
    let mut nums = vec![0; n];
    for num in nums.iter_mut() {
        *num = it.next().unwrap();
    }
    print!("{}", nums.select_nth_unstable(k - 1).1);
}