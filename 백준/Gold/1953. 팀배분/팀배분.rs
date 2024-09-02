use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut output = String::new();
    let mut adj = vec![Vec::new(); n];
    for i in 0..n {
        let count = input.next().unwrap();
        for _ in 0..count {
            let num = input.next().unwrap() - 1;
            adj[i].push(num);
            adj[num].push(i);
        }
    }
    let (blue_team, white_team) = separate_graph(&adj);
    output.push_str(&format!("{}\n", blue_team.len()));
    for item in blue_team.iter() {
        output.push_str(&format!("{} ", item));
    }
    output.push('\n');
    output.push_str(&format!("{}\n", white_team.len()));
    for item in white_team.iter() {
        output.push_str(&format!("{} ", item));
    }
    print!("{output}");
}

fn separate_graph(adj: &[Vec<usize>]) -> (Vec<usize>, Vec<usize>) {
    let mut nodes_color = vec![0usize; adj.len()];
    for start in 0..adj.len() {
        if nodes_color[start] != 0 {
            continue;
        }
        nodes_color[start] = 1;
        let mut q = VecDeque::new();
        q.push_back(start);
        while !q.is_empty() {
            while let Some(node) = q.pop_front() {
                for &next in &adj[node] {
                    if nodes_color[next] == 0 {
                        nodes_color[next] = 3 - nodes_color[node];
                        q.push_back(next);
                    }
                }
            }
        }
    }
    (
        nodes_color
            .iter()
            .enumerate()
            .filter(|&(_, color)| *color == 1)
            .map(|(i, _)| i + 1)
            .collect(),
        nodes_color
            .iter()
            .enumerate()
            .filter(|&(_, color)| *color == 2)
            .map(|(i, _)| i + 1)
            .collect(),
    )
}