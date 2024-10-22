use std::{
    collections::HashSet,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (n, m) = (input.next().unwrap(), input.next().unwrap());
    let mut adj = vec![Vec::new(); n + 1];
    for _ in 0..m {
        let (a, b) = (input.next().unwrap(), input.next().unwrap());
        adj[a].push(b);
        adj[b].push(a);
    }
    let mut set = HashSet::new();
    for &node in adj[1].iter() {
        set.insert(node);
        for &second_node in adj[node].iter() {
            set.insert(second_node);
        }
    }
    print!("{}", if set.is_empty() { 0 } else { set.len() - 1 });
}