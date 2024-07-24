use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace();
    let k = it.next().unwrap().parse::<usize>().unwrap();
    let mut signs = vec![' '; k];
    for sign in signs.iter_mut() {
        *sign = it.next().unwrap().chars().next().unwrap();
    }
    let mut visited = vec![false; 11];
    let mut ans = vec![10; k + 1];
    for i in (0..10).rev() {
        ans[0] = i;
        visited[i] = true;
        max_dfs(&signs, &mut visited, &mut ans, 1);
        visited[i] = false;
        if ans[k] != 10 {
            for num in ans.iter() {
                print!("{}", num);
            }
            println!();
            break;
        }
    }
    for i in 0..=k {
        ans[i] = 10;
        visited[i] = false;
    }
    for i in 0..10 {
        ans[0] = i;
        visited[i] = true;
        min_dfs(&signs, &mut visited, &mut ans, 1);
        visited[i] = false;
        if ans[k] != 10 {
            for num in ans.iter() {
                print!("{}", num);
            }
            break;
        }
    }
}

fn max_dfs(signs: &[char], visited: &mut [bool], ans: &mut [usize], idx: usize) {
    if idx == ans.len() {
        return;
    }
    for i in (0..10).rev() {
        if !visited[i]
            && ((signs[idx - 1] == '<' && ans[idx - 1] < i)
                || (signs[idx - 1] == '>' && ans[idx - 1] > i))
        {
            ans[idx] = i;
            visited[i] = true;
            max_dfs(signs, visited, ans, idx + 1);
            visited[i] = false;
            if ans[ans.len() - 1] != 10 {
                break;
            }
        }
    }
}

fn min_dfs(signs: &[char], visited: &mut [bool], ans: &mut [usize], idx: usize) {
    if idx == ans.len() {
        return;
    }
    for i in 0..10 {
        if !visited[i]
            && ((signs[idx - 1] == '<' && ans[idx - 1] < i)
                || (signs[idx - 1] == '>' && ans[idx - 1] > i))
        {
            ans[idx] = i;
            visited[i] = true;
            min_dfs(signs, visited, ans, idx + 1);
            visited[i] = false;
            if ans[ans.len() - 1] != 10 {
                break;
            }
        }
    }
}