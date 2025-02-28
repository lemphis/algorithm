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

    let (node, _) = dfs(&tree, 0, 0);
    let (_, max_weight) = dfs(&tree, node, n);

    print!("{max_weight}");
}

fn dfs(tree: &[Vec<(usize, usize)>], node: usize, parent: usize) -> (usize, usize) {
    let (mut fartest_node, mut max_weight) = (node, 0);
    for (next, weight) in tree[node].iter() {
        if *next != parent {
            let (far_node, far_weight) = dfs(tree, *next, node);
            if far_weight + weight > max_weight {
                max_weight = far_weight + weight;
                fartest_node = far_node;
            }
        }
    }
    (fartest_node, max_weight)
}