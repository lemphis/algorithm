use std::{collections::VecDeque, io};

fn main() {
    let input = io::read_to_string(io::stdin()).unwrap();
    let mut input = input.split_ascii_whitespace();
    let (n, m) = (
        input.next().unwrap().parse::<usize>().unwrap(),
        input.next().unwrap().parse::<usize>().unwrap(),
    );
    let mut map = Vec::with_capacity(m);
    for _ in 0..m {
        map.push(input.next().unwrap().chars().collect::<Vec<char>>());
    }
    let mut visited = vec![vec![false; n]; m];
    let mut white = 0;
    let mut blue = 0;
    for i in 0..m {
        for j in 0..n {
            if map[i][j] == 'W' {
                white += bfs(&map, (i, j), m, n, &mut visited, 'W');
            } else {
                blue += bfs(&map, (i, j), m, n, &mut visited, 'B');
            }
        }
    }
    print!("{} {}", white, blue);
}

fn bfs(
    map: &[Vec<char>],
    point: (usize, usize),
    row: usize,
    col: usize,
    visited: &mut [Vec<bool>],
    team: char,
) -> usize {
    if visited[point.0][point.1] {
        return 0;
    }
    let mut cnt: usize = 1;
    let mut q = VecDeque::new();
    q.push_back(point);
    visited[point.0][point.1] = true;
    while let Some((r, c)) = q.pop_front() {
        [
            (r.saturating_sub(1), c),
            (r, (c + 1).min(col - 1)),
            ((r + 1).min(row - 1), c),
            (r, c.saturating_sub(1)),
        ]
        .iter()
        .for_each(|&(next_r, next_c)| {
            if map[next_r][next_c] == team && !visited[next_r][next_c] {
                q.push_back((next_r, next_c));
                visited[next_r][next_c] = true;
                cnt += 1;
            }
        });
    }
    cnt.pow(2)
}
