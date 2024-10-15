use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (n, m, r) = (
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
    );
    let mut adj = vec![Vec::new(); n + 1];
    for _ in 0..m {
        let (u, v) = (input.next().unwrap(), input.next().unwrap());
        adj[u].push(v);
        adj[v].push(u);
    }
    for row in adj.iter_mut().skip(1) {
        if !row.is_empty() {
            row.sort_unstable();
        }
    }
    let mut visited = vec![0; n + 1];
    let mut idx = 1;
    dfs(&adj, &mut visited, r, &mut idx);
    let mut output = String::new();
    for item in visited.iter().skip(1) {
        output.push_str(&format!("{item}\n"));
    }
    print!("{output}");
}

fn dfs(adj: &[Vec<usize>], visited: &mut [usize], node: usize, idx: &mut usize) {
    if visited[node] > 0 {
        return;
    }
    visited[node] = *idx;
    *idx += 1;
    for &next in adj[node].iter() {
        if visited[next] == 0 {
            dfs(adj, visited, next, idx);
        }
    }
}