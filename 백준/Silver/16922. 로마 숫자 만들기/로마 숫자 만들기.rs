use std::{
    collections::HashSet,
    io::{self, stdin},
};

const NUMS: [usize; 4] = [1, 5, 10, 50];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut set = HashSet::new();
    let mut nums = vec![0; n];
    dfs(n, &mut nums, &mut set, 0);
    print!("{}", set.len());
}

fn dfs(n: usize, nums: &mut [usize], set: &mut HashSet<usize>, depth: usize) {
    if depth == n {
        set.insert(nums.iter().sum());
        return;
    }
    for num in NUMS {
        if depth > 0 && nums[depth - 1] > num {
            continue;
        }
        nums[depth] = num;
        dfs(n, nums, set, depth + 1);
    }
}