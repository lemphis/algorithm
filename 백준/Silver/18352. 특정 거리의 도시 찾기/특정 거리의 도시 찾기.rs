use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024 * 1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m, k, x) = (f(), f(), f(), f());
    let mut adj = vec![Vec::new(); n];
    for _ in 0..m {
        let (a, b) = (f() - 1, f() - 1);
        adj[a].push(b);
    }

    let dist = dijkstra(&adj, x - 1);
    let mut ans: Vec<usize> = dist
        .iter()
        .enumerate()
        .filter(|&(_, &d)| d == k)
        .map(|(idx, _)| idx + 1)
        .collect();
    if ans.is_empty() {
        print!("-1");
    } else {
        ans.sort_unstable();
        print!(
            "{}",
            ans.iter()
                .map(usize::to_string)
                .collect::<Vec<_>>()
                .join("\n")
        );
    }
}

fn dijkstra(adj: &[Vec<usize>], start: usize) -> Vec<usize> {
    let len = adj.len();
    let mut dist = vec![usize::MAX; len];
    dist[start] = 0;

    let mut pq = BinaryHeap::new();
    pq.push((Reverse(0), start));

    while let Some((Reverse(cost), node)) = pq.pop() {
        for next in adj[node].iter() {
            if dist[*next] == usize::MAX {
                pq.push((Reverse(cost + 1), *next));
            }
            dist[*next] = dist[*next].min(dist[node] + 1);
        }
    }

    dist
}