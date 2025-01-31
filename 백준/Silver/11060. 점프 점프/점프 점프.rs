use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: Vec<usize> = (0..n).map(|_| f()).collect();
    let mut q = VecDeque::new();
    q.push_back((0, 0));
    let mut min_count = n;
    let mut visited = vec![false; n];
    while let Some((idx, count)) = q.pop_front() {
        if idx == n - 1 {
            min_count = min_count.min(count);
            print!("{min_count}");
            return;
        }
        for i in 1..=nums[idx] {
            if idx + i < n && nums[idx + i] > 0 && !visited[idx + i] {
                q.push_back((idx + i, count + 1));
                visited[idx + i] = true;
            }
        }
    }
    print!("-1");
}