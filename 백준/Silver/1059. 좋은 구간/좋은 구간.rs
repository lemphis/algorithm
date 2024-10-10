use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let l = input.next().unwrap();
    let mut nums = input.by_ref().take(l).collect::<Vec<_>>();
    let n = input.next().unwrap();
    nums.sort();
    let mut idx = usize::MAX;
    for i in 0..l {
        if n > nums[i] {
            idx = i;
        }
        if n == nums[i] {
            print!("0");
            return;
        }
    }
    print!(
        "{}",
        if idx == usize::MAX {
            (nums[0] - n - 1) + (nums[0] - n) * (n - 1)
        } else {
            (nums[idx + 1] - n) * (n - nums[idx] - 1) + (nums[idx + 1] - n - 1)
        }
    );
}