use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<f64>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut nums = (0..n as usize).map(|_| f()).collect::<Vec<_>>();
    nums.sort_by(|a, b| b.total_cmp(a));
    while nums.len() > 1 {
        let last = nums.pop().unwrap();
        nums[0] += last / 2.0;
    }
    print!("{}", nums[0]);
}