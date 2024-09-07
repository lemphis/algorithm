use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let (n, _) = (input.next().unwrap(), input.next().unwrap());
    let nums = input.collect::<Vec<_>>();
    let mut max_num = 0;
    find_max_num(&nums, 0, &mut max_num, n, 0);
    print!("{max_num}");
}

fn find_max_num(nums: &Vec<usize>, sum: usize, max_num: &mut usize, n: usize, depth: usize) {
    if sum.to_string().len() > n.to_string().len() {
        return;
    }
    if sum <= n && sum > *max_num {
        *max_num = sum;
    }
    for &num in nums.iter() {
        find_max_num(
            nums,
            sum + (10_i32.pow(depth as u32) as usize * num),
            max_num,
            n,
            depth + 1,
        );
    }
}