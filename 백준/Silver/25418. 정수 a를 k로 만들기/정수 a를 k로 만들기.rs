use std::{
    collections::{HashSet, VecDeque},
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (a, k) = (f(), f());
    print!("{}", bfs(a, k));
}

fn bfs(a: usize, k: usize) -> usize {
    let (mut q, mut visited) = (VecDeque::new(), HashSet::new());
    q.push_back((a, 0usize));
    visited.insert(a);
    while !q.is_empty() {
        let (num, times) = q.pop_front().unwrap();
        if num == k {
            return times;
        }
        if num + 1 <= k && !visited.contains(&(num + 1)) {
            q.push_back((num + 1, times + 1));
            visited.insert(num + 1);
        }
        if num * 2 <= k && !visited.contains(&(num * 2)) {
            q.push_back((num * 2, times + 1));
            visited.insert(num * 2);
        }
    }
    unreachable!()
}