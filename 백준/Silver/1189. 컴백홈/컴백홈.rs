use std::io::{self};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let input = io::read_to_string(io::stdin()).unwrap();
    let mut input = input.split_ascii_whitespace();
    let (r, c, k) = (
        input.next().unwrap().parse::<i32>().unwrap(),
        input.next().unwrap().parse::<i32>().unwrap(),
        input.next().unwrap().parse::<i32>().unwrap(),
    );
    let mut map = Vec::with_capacity(r as usize);
    for _ in 0..r {
        map.push(input.next().unwrap().chars().collect::<Vec<char>>());
    }
    let mut visited = vec![vec![false; c as usize]; r as usize];
    visited[(r - 1) as usize][0] = true;
    let mut ans = 0;
    dfs(r, c, (r - 1) as i32, 0, &map, k, &mut visited, 1, &mut ans);
    print!("{}", ans);
}

fn dfs(
    r: i32,
    c: i32,
    now_r: i32,
    now_c: i32,
    map: &Vec<Vec<char>>,
    k: i32,
    visited: &mut Vec<Vec<bool>>,
    cnt: i32,
    ans: &mut i32,
) {
    if now_r == 0 && now_c == c - 1 && cnt == k {
        *ans += 1;
    }
    for i in 0..DR.len() {
        let next_r = now_r + DR[i];
        let next_c = now_c + DC[i];
        if next_r >= 0
            && next_r < r
            && next_c >= 0
            && next_c < c
            && map[next_r as usize][next_c as usize] != 'T'
            && !visited[next_r as usize][next_c as usize]
        {
            visited[next_r as usize][next_c as usize] = true;
            dfs(r, c, next_r, next_c, map, k, visited, cnt + 1, ans);
            visited[next_r as usize][next_c as usize] = false;
        }
    }
}
