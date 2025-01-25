use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: Vec<Vec<usize>> = (0..n).map(|_| (0..n).map(|_| f()).collect()).collect();
    print!("{}", dfs(&nums, 0, 0, nums.len()));
}

fn dfs(nums: &[Vec<usize>], r: usize, c: usize, len: usize) -> usize {
    if len == 1 {
        return nums[r][c];
    }
    let next_len = len / 2;
    let mut v = [
        dfs(nums, r, c, next_len),
        dfs(nums, r + next_len, c, next_len),
        dfs(nums, r, c + next_len, next_len),
        dfs(nums, r + next_len, c + next_len, next_len),
    ];
    v.sort_unstable();
    v[1]
}