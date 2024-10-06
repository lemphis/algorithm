use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<f64>);
    let mut nums = input.skip(1).collect::<Vec<_>>();
    let mut max = nums[0];
    for i in 1..nums.len() {
        if nums[i] * nums[i - 1] > nums[i] {
            nums[i] *= nums[i - 1];
        }
        max = max.max(nums[i]);
    }
    print!("{:.3}", max);
}