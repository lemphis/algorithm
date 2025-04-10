use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();

    let mut adj = vec![Vec::new(); n + 1];
    let mut parent = vec![0; n];
    for (i, p) in parent.iter_mut().enumerate() {
        *p = i;
    }
    for _ in 0..n - 1 {
        let (s, e) = (f(), f());
        adj[s].push(e);
        adj[e].push(s);
    }

    let mut parent = vec![0; n + 1];
    let mut q = VecDeque::new();
    q.push_back((1, 0));
    while let Some((node, from)) = q.pop_front() {
        for next in adj[node].iter() {
            if *next != from {
                parent[*next] = node;
                q.push_back((*next, node));
            }
        }
    }

    let mut output = String::new();
    let m = f();
    for _ in 0..m {
        let (a, b) = (f(), f());
        output.push_str(&format!("{}\n", find_lca(&parent, a, b)));
    }

    print!("{output}");
}

fn find_lca(parent: &[usize], a: usize, b: usize) -> usize {
    let path_a = get_path(parent, a);
    let path_b = get_path(parent, b);

    path_a
        .iter()
        .rev()
        .zip(path_b.iter().rev())
        .take_while(|(a, b)| a == b)
        .last()
        .map(|(x, _)| *x)
        .unwrap_or(0)
}

fn get_path(parent: &[usize], node: usize) -> Vec<usize> {
    let mut path = Vec::new();
    let mut cur = node;
    while cur != 0 {
        path.push(cur);
        cur = parent[cur];
    }

    path
}