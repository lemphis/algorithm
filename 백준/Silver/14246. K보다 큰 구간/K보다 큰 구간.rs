use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: Vec<_> = (0..n).map(|_| f()).collect();
    let k = f();

    let (mut l, mut sum, mut count) = (0, 0, 0);
    for r in 0..n {
        sum += nums[r];
        while sum > k {
            sum -= nums[l];
            l += 1;
            count += n - r;
        }
    }

    print!("{count}");
}