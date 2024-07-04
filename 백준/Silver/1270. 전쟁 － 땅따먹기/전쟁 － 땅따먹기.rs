use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let n = input.next().unwrap() as usize;
    for _ in 0..n {
        let ti = input.next().unwrap() as usize;
        let mut nums = vec![0; ti];
        for num in nums.iter_mut() {
            *num = input.next().unwrap();
        }
        let major = boyer_moore_majority(&nums);
        let mut count = 0;
        for &num in &nums {
            if major == num {
                count += 1;
            }
        }
        if count > ti / 2 {
            println!("{}", major);
        } else {
            println!("SYJKGW");
        }
    }
}

fn boyer_moore_majority(nums: &[i64]) -> i64 {
    let mut major = 0;
    let mut count = 0;
    for &num in nums {
        if count == 0 {
            major = num;
        }
        count += if major == num { 1 } else { -1 }
    }
    major
}