use std::{
    cmp,
    collections::VecDeque,
    io::{stdin, Read},
};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut arr = Vec::new();
    for _ in 0..n {
        arr.push(Vec::new());
    }
    for _ in 0..n - 1 {
        let a = input.next().unwrap() - 1;
        let b = input.next().unwrap() - 1;
        let c = input.next().unwrap();
        arr[a].push((b, c));
        arr[b].push((a, c));
    }
    print!("{}", bfs(&arr));
}

fn bfs(arr: &Vec<Vec<(usize, usize)>>) -> usize {
    let mut max = 0;
    for (next, path_len) in &arr[0] {
        let mut q = VecDeque::new();
        q.push_back((*next, *path_len));
        let mut visited = Vec::with_capacity(arr.len());
        for _ in 0..arr.len() {
            visited.push(false);
        }
        visited[0] = true;
        while !q.is_empty() {
            let (next, path_len) = q.pop_front().unwrap();
            visited[next] = true;
            max = cmp::max(max, path_len);
            for (next_next, next_path_len) in &arr[next] {
                if !visited[*next_next] {
                    q.push_back((*next_next, path_len + next_path_len));
                }
            }
        }
    }
    max
}
