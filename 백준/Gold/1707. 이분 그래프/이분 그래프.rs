use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let k = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..k {
        let (v, e) = (input.next().unwrap(), input.next().unwrap());
        let mut adj = vec![Vec::new(); v];
        for _ in 0..e {
            let (a, b) = (input.next().unwrap(), input.next().unwrap());
            adj[a - 1].push(b - 1);
            adj[b - 1].push(a - 1);
        }
        output.push_str(if is_bipartite(&adj) { "YES\n" } else { "NO\n" });
    }
    print!("{output}");
}

fn is_bipartite(adj: &[Vec<usize>]) -> bool {
    let mut nodes_color = vec![0; adj.len()];
    for start in 0..adj.len() {
        if nodes_color[start] != 0 {
            continue;
        }
        let mut q = VecDeque::new();
        q.push_back(start);
        while !q.is_empty() {
            while let Some(node) = q.pop_front() {
                for &next in &adj[node] {
                    if nodes_color[next] == 0 {
                        nodes_color[next] = 3 - nodes_color[node];
                        q.push_back(next);
                    } else if nodes_color[next] == nodes_color[node] {
                        return false;
                    }
                }
            }
        }
    }
    true
}