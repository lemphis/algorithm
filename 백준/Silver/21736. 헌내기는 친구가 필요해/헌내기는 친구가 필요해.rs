use std::{
    collections::VecDeque,
    io::{self, stdin},
};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, m) = (f().parse::<usize>().unwrap(), f().parse::<usize>().unwrap());
    let (mut map, mut visited) = (vec![vec!['O'; m]; n], vec![vec![false; m]; n]);
    let mut doyeon_pos = (0, 0);
    for r in 0..n {
        for (c, ch) in f().chars().enumerate() {
            match ch {
                'I' => doyeon_pos = (r, c),
                _ => map[r][c] = ch,
            }
        }
    }
    let ans = bfs(&map, &mut visited, doyeon_pos);
    if ans > 0 {
        print!("{ans}")
    } else {
        print!("TT");
    }
}

fn bfs(map: &[Vec<char>], visited: &mut [Vec<bool>], start: (usize, usize)) -> usize {
    let mut q = VecDeque::new();
    q.push_back(start);
    visited[start.0][start.1] = true;
    let mut ans = 0;
    while !q.is_empty() {
        let (r, c) = q.pop_front().unwrap();
        if map[r][c] == 'P' {
            ans += 1;
        }
        for i in 0..4 {
            let (next_r, next_c) = (r as i32 + DR[i], c as i32 + DC[i]);
            if next_r >= 0
                && next_r < map.len() as i32
                && next_c >= 0
                && next_c < map[r].len() as i32
                && map[next_r as usize][next_c as usize] != 'X'
                && !visited[next_r as usize][next_c as usize]
            {
                q.push_back((next_r as usize, next_c as usize));
                visited[next_r as usize][next_c as usize] = true;
            }
        }
    }
    ans
}