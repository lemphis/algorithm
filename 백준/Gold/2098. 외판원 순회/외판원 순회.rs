use std::io;

const VISITED_MAX: usize = 1_000_000_000;
const INITIALIZED_MAX: usize = 2_000_000_000;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let adj = input
        .collect::<Vec<_>>()
        .chunks(n)
        .map(Vec::from)
        .collect::<Vec<_>>();
    let mut dp = vec![vec![INITIALIZED_MAX; 1 << n]; n];
    print!("{}", tsp(0, 1, &adj, &mut dp));
}

fn tsp(cur_node: usize, visited: usize, adj: &Vec<Vec<usize>>, dp: &mut Vec<Vec<usize>>) -> usize {
    if visited == (1 << adj.len()) - 1 {
        return if adj[cur_node][0] > 0 {
            adj[cur_node][0]
        } else {
            VISITED_MAX
        };
    }
    if dp[cur_node][visited] != INITIALIZED_MAX {
        return dp[cur_node][visited];
    }
    for node in 1..adj.len() {
        if 1 << node & visited == 0 && adj[cur_node][node] > 0 {
            dp[cur_node][visited] = dp[cur_node][visited]
                .min(tsp(node, visited | 1 << node, adj, dp) + adj[cur_node][node]);
        }
    }
    dp[cur_node][visited]
}