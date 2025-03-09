use std::{
    cmp::Reverse,
    collections::{hash_map, BinaryHeap, HashMap},
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024 * 1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, d) = (f(), f());
    let mut adj = vec![HashMap::new(); 10_001];
    for _ in 0..n {
        let (s, e, w) = (f(), f(), f());
        if e > d {
            continue;
        }
        if e - s <= w {
            continue;
        }
        match adj[s].entry(e) {
            hash_map::Entry::Vacant(entry) => {
                entry.insert(w);
            }
            hash_map::Entry::Occupied(mut entry) => {
                *entry.get_mut() = (*entry.get()).min(w);
            }
        }
    }

    print!("{}", dijkstra(&adj, d));
}

fn dijkstra(adj: &[HashMap<usize, usize>], d: usize) -> usize {
    let mut dist = vec![usize::MAX; adj.len()];
    dist[0] = 0;

    let mut pq = BinaryHeap::new();
    pq.push((Reverse(0), 0));

    while let Some((Reverse(cost), pos)) = pq.pop() {
        if pos == d {
            return cost;
        }
        for (next, next_cost) in adj[pos].iter() {
            let min = dist[*next].min(dist[pos] + *next_cost);
            pq.push((Reverse(min), *next));
            dist[*next] = min;
        }

        let min = dist[pos + 1].min(dist[pos] + 1);
        pq.push((Reverse(min), pos + 1));
        dist[pos + 1] = min;
    }

    unreachable!()
}