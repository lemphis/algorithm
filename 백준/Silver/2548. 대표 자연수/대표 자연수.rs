use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut nums = input.collect::<Vec<_>>();
    nums.sort();
    print!("{}", nums[if n & 1 == 0 { n / 2 - 1 } else { n / 2 }]);
}