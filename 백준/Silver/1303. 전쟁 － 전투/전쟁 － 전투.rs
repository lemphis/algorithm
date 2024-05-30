use std::{collections::VecDeque, io};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let input = io::read_to_string(io::stdin()).unwrap();
    let mut input = input.split_ascii_whitespace();
    let (n, m) = (
        input.next().unwrap().parse::<i32>().unwrap(),
        input.next().unwrap().parse::<i32>().unwrap(),
    );
    let mut map = Vec::with_capacity(m as usize);
    for _ in 0..m {
        map.push(input.next().unwrap().chars().collect::<Vec<char>>());
    }
    let mut visited = vec![vec![false; n as usize]; m as usize];
    let mut white = 0;
    let mut blue = 0;
    for i in 0..m {
        for j in 0..n {
            if map[i as usize][j as usize] == 'W' {
                white += bfs(&map, (i, j), m, n, &mut visited, 'W');
            } else {
                blue += bfs(&map, (i, j), m, n, &mut visited, 'B');
            }
        }
    }
    print!("{} {}", white, blue);
}

fn bfs(
    map: &Vec<Vec<char>>,
    point: (i32, i32),
    row: i32,
    col: i32,
    visited: &mut Vec<Vec<bool>>,
    team: char,
) -> i32 {
    if visited[point.0 as usize][point.1 as usize] {
        return 0;
    }
    let mut cnt: i32 = 1;
    let mut q = VecDeque::new();
    q.push_back(point);
    visited[point.0 as usize][point.1 as usize] = true;
    while !q.is_empty() {
        let now = q.pop_front().unwrap();
        for i in 0..DR.len() {
            let next_r = now.0 + DR[i];
            let next_c = now.1 + DC[i];
            if next_r >= 0
                && next_r < row
                && next_c >= 0
                && next_c < col
                && map[next_r as usize][next_c as usize] == team
                && !visited[next_r as usize][next_c as usize]
            {
                q.push_back((next_r, next_c));
                visited[next_r as usize][next_c as usize] = true;
                cnt += 1;
            }
        }
    }
    cnt.pow(2)
}
