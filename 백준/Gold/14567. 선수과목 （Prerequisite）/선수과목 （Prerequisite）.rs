use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (n, m) = (input.next().unwrap(), input.next().unwrap());
    let mut graph = vec![Vec::new(); n];
    let mut in_degrees = vec![0; n];
    for _ in 0..m {
        let (a, b) = (input.next().unwrap() - 1, input.next().unwrap() - 1);
        graph[a].push(b);
        in_degrees[b] += 1;
    }
    print!(
        "{}",
        topology_sort(&mut graph, &mut in_degrees)
            .iter()
            .map(usize::to_string)
            .collect::<Vec<String>>()
            .join(" ")
    );
}

fn topology_sort(graph: &mut [Vec<usize>], in_degrees: &mut [usize]) -> Vec<usize> {
    let len = in_degrees.len();
    let mut list = vec![0; len];
    let mut term = 1;
    let mut q = VecDeque::new();
    for _ in 0..len {
        for i in 0..len {
            if in_degrees[i] == 0 {
                q.push_back(i);
                in_degrees[i] = usize::MAX;
                list[i] = term;
            }
        }
        while let Some(top) = q.pop_front() {
            for &next in graph[top].iter() {
                in_degrees[next] -= 1;
            }
            graph[top].clear();
        }
        term += 1;
    }
    list
}