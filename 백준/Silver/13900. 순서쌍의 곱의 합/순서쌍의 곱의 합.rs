use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: Vec<usize> = (0..n).map(|_| f()).collect();
    let total_sum: usize = nums.iter().sum();
    let mut sum = 0;
    for &num in nums.iter() {
        sum += (total_sum - num) * num;
    }
    print!("{}", sum / 2);
}