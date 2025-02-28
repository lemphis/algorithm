use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut tree = vec![Vec::new(); n];
    for _ in 0..n - 1 {
        let (a, b, w) = (f() - 1, f() - 1, f());
        tree[a].push((b, w));
        tree[b].push((a, w));
    }

    let mut max_weight = 0;
    for i in 0..n {
        let mut visited = vec![false; n];
        visited[i] = true;
        max_weight = max_weight.max(dfs(i, &tree, &mut visited));
    }

    print!("{max_weight}");
}

fn dfs(start: usize, tree: &[Vec<(usize, usize)>], visited: &mut [bool]) -> usize {
    let mut max_weight = 0;
    for &(next, weight) in tree[start].iter() {
        if !visited[next] {
            visited[next] = true;
            max_weight = max_weight.max(dfs(next, tree, visited) + weight);
            visited[next] = false;
        }
    }
    max_weight
}