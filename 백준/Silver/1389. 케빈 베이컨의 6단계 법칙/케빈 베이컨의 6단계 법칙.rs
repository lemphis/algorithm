use std::{
    collections::VecDeque,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut adj = [[false; 100]; 100];
    for _ in 0..m {
        let (a, b) = (f() - 1, f() - 1);
        adj[a][b] = true;
        adj[b][a] = true;
    }
    let (mut min_sum, mut min_num) = (usize::MAX, 0);
    for start in 0..n {
        let mut distances = vec![None; n];
        distances[start] = Some(0);
        let mut q = VecDeque::new();
        q.push_back(start);
        while let Some(cur) = q.pop_front() {
            for next in 0..n {
                if adj[cur][next] && distances[next].is_none() {
                    distances[next] = Some(distances[cur].unwrap() + 1);
                    q.push_back(next);
                }
            }
        }

        let sum: usize = distances.into_iter().flatten().sum();
        if sum < min_sum {
            min_sum = sum;
            min_num = start;
        }
    }

    print!("{}", min_num + 1);
}