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
    let mut map = vec![vec!['O'; m]; n];
    let mut doyeon_pos = (0, 0);
    for r in 0..n {
        for (c, ch) in f().chars().enumerate() {
            match ch {
                'I' => doyeon_pos = (r, c),
                _ => map[r][c] = ch,
            }
        }
    }
    let ans = bfs(&mut map, doyeon_pos);
    print!(
        "{}",
        if ans > 0 {
            ans.to_string()
        } else {
            String::from("TT")
        }
    );
}

fn bfs(map: &mut [Vec<char>], start: (usize, usize)) -> usize {
    let mut q = VecDeque::from([start]);
    map[start.0][start.1] = 'X';
    let mut ans = 0;
    while let Some((r, c)) = q.pop_front() {
        for i in 0..4 {
            let (next_r, next_c) = (r as i32 + DR[i], c as i32 + DC[i]);
            if next_r >= 0
                && next_r < map.len() as i32
                && next_c >= 0
                && next_c < map[r].len() as i32
                && map[next_r as usize][next_c as usize] != 'X'
            {
                if map[next_r as usize][next_c as usize] == 'P' {
                    ans += 1;
                }
                map[next_r as usize][next_c as usize] = 'X';
                q.push_back((next_r as usize, next_c as usize));
            }
        }
    }
    ans
}