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
    let mut ans = usize::MAX;
    dfs(&ingredients, &mut ans, (1, 0), 0);
    print!("{ans}");
}

fn dfs(ingredients: &[(usize, usize)], ans: &mut usize, sb: (usize, usize), start: usize) {
    if start == ingredients.len() {
        return;
    }
    for i in start..ingredients.len() {
        let next_sb = (sb.0 * ingredients[i].0, sb.1 + ingredients[i].1);
        *ans = (*ans).min(next_sb.0.abs_diff(next_sb.1));
        dfs(ingredients, ans, next_sb, i + 1);
    }
}