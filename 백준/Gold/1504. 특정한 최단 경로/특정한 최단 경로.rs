use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(64);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, e) = (f(), f());
    let mut adj = vec![Vec::new(); n];
    for _ in 0..e {
        let (a, b, c) = (f() - 1, f() - 1, f());
        adj[a].push((b, c));
        adj[b].push((a, c));
    }
    let (v1, v2) = (f() - 1, f() - 1);
    let (v1_dist, v2_dist) = (dijkstra(&adj, v1), dijkstra(&adj, v2));
    let min_dist = (v1_dist[0]
        .saturating_add(v1_dist[v2])
        .saturating_add(v2_dist[n - 1]))
    .min(
        v2_dist[0]
            .saturating_add(v2_dist[v1])
            .saturating_add(v1_dist[n - 1]),
    );

    if min_dist == usize::MAX {
        print!("-1");
    } else {
        print!("{min_dist}")
    }
}

fn dijkstra(adj: &[Vec<(usize, usize)>], start: usize) -> Vec<usize> {
    let mut pq = BinaryHeap::new();
    pq.push((Reverse(0), start));

    let mut dist = vec![usize::MAX; adj.len()];
    dist[start] = 0;

    while let Some((Reverse(_), node)) = pq.pop() {
        for &(next, next_cost) in adj[node].iter() {
            let min_cost = dist[next].min(dist[node] + next_cost);
            if dist[next] > min_cost {
                dist[next] = min_cost;
                pq.push((Reverse(dist[next]), next));
            }
        }
    }

    dist
}