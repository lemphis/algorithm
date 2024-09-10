use std::{
    collections::VecDeque,
    io::{self, stdin},
};

const MAX: usize = 100_001;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (a, b, n, m) = (
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
    );
    print!("{}", bfs(a, b, n, m));
}

fn bfs(a: usize, b: usize, n: usize, m: usize) -> usize {
    let mut q = VecDeque::new();
    let mut visited = [false; MAX];
    q.push_back((n, 0));
    visited[n] = true;
    while !q.is_empty() {
        let (now_pos, now_count) = q.pop_front().unwrap();
        if now_pos == m {
            return now_count;
        }
        if now_pos < MAX - 1 && !visited[now_pos + 1] {
            visited[now_pos + 1] = true;
            q.push_back((now_pos + 1, now_count + 1));
        }
        if now_pos >= 1 && !visited[now_pos - 1] {
            visited[now_pos - 1] = true;
            q.push_back((now_pos - 1, now_count + 1));
        }
        if now_pos < MAX - a && !visited[now_pos + a] {
            visited[now_pos + a] = true;
            q.push_back((now_pos + a, now_count + 1));
        }
        if now_pos >= a && !visited[now_pos - a] {
            visited[now_pos - a] = true;
            q.push_back((now_pos - a, now_count + 1));
        }
        if now_pos < MAX - b && !visited[now_pos + b] {
            visited[now_pos + b] = true;
            q.push_back((now_pos + b, now_count + 1));
        }
        if now_pos >= b && !visited[now_pos - b] {
            visited[now_pos - b] = true;
            q.push_back((now_pos - b, now_count + 1));
        }
        if now_pos < MAX / a && !visited[now_pos * a] {
            visited[now_pos * a] = true;
            q.push_back((now_pos * a, now_count + 1));
        }
        if now_pos < MAX / b && !visited[now_pos * b] {
            visited[now_pos * b] = true;
            q.push_back((now_pos * b, now_count + 1));
        }
    }
    unreachable!()
}