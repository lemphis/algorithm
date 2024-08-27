use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut sequences = input.collect::<Vec<_>>();
    sequences.sort();
    let mut visited = vec![false; 2_000_001];
    dfs(0, n, 0, &sequences, &mut visited);
    print!(
        "{}",
        visited
            .iter()
            .enumerate()
            .skip(1)
            .find(|&(_, &b)| !b)
            .unwrap()
            .0
    );
}

fn dfs(depth: usize, n: usize, sum: usize, sequences: &[usize], visited: &mut [bool]) {
    if depth == n {
        visited[sum] = true;
        return;
    }
    dfs(depth + 1, n, sum, sequences, visited);
    dfs(depth + 1, n, sum + sequences[depth], sequences, visited);
}