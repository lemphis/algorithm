use std::{
    io::{self, stdin},
    usize,
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let ingredients = (0..n).map(|_| (f(), f())).collect::<Vec<_>>();
    let mut visited = vec![false; n];
    let mut ans = usize::MAX;
    dfs(&ingredients, &mut visited, &mut ans, (1, 0), 0);
    print!("{ans}");
}

fn dfs(
    ingredients: &[(usize, usize)],
    visited: &mut [bool],
    ans: &mut usize,
    sb: (usize, usize),
    depth: usize,
) {
    if depth == ingredients.len() {
        return;
    }
    for i in 0..ingredients.len() {
        if !visited[i] {
            visited[i] = true;
            let next_sb = (sb.0 * ingredients[i].0, sb.1 + ingredients[i].1);
            *ans = *ans.min(&mut next_sb.0.abs_diff(next_sb.1));
            dfs(ingredients, visited, ans, next_sb, depth + 1);
            visited[i] = false;
        }
    }
}