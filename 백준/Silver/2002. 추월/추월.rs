use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();
    let in_nums: HashMap<&str, usize> = (0..n).map(|i| (f(), i)).collect();
    let out_nums: Vec<&str> = (0..n).map(|_| f()).collect();
    let mut count = 0;
    for i in 0..n - 1 {
        for j in i + 1..n {
            if in_nums[out_nums[i]] > in_nums[out_nums[j]] {
                count += 1;
                break;
            }
        }
    }
    print!("{count}");
}