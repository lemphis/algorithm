use std::{
    collections::VecDeque,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let (a, b) = {
        let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
        (it.next().unwrap(), it.next().unwrap())
    };
    print!("{}", bfs(a, b));
}

fn bfs(a: usize, b: usize) -> i32 {
    let mut q = VecDeque::new();
    q.push_back((a, 1));
    while !q.is_empty() {
        let (num, count) = q.pop_front().unwrap();
        if num == b {
            return count;
        }
        if num * 2 <= b {
            q.push_back((num * 2, count + 1));
        }
        if num * 10 + 1 <= b {
            q.push_back((num * 10 + 1, count + 1));
        }
    }
    -1
}