use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let mut tree = vec![Vec::new(); n];
    for _ in 0..n {
        let node = f() as usize;
        loop {
            let child = f();
            if child == -1 {
                break;
            }
            let child = child as usize;
            let weight = f() as usize;
            tree[node - 1].push((child - 1, weight));
        }
    }

    let (fartest_node, _) = dfs(&tree, 0, n);
    let (_, max_len) = dfs(&tree, fartest_node, n);

    print!("{max_len}");
}

fn dfs(tree: &[Vec<(usize, usize)>], start: usize, parent: usize) -> (usize, usize) {
    let (mut fartest_node, mut max_weight) = (start, 0);
    for (next, weight) in tree[start].iter() {
        if *next != parent {
            let (far_node, far_weight) = dfs(tree, *next, start);
            if far_weight + weight > max_weight {
                max_weight = far_weight + weight;
                fartest_node = far_node;
            }
        }
    }
    (fartest_node, max_weight)
}