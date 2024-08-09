use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<i32>);
    let (n, k) = (it.next().unwrap() as usize, it.next().unwrap() as usize);
    let mut nums = vec![0; n];
    for num in nums.iter_mut() {
        *num = it.next().unwrap();
    }
    nums.sort();
    print!("{}", nums[k - 1]);
}