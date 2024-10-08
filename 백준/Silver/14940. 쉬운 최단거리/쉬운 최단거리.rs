use std::{
    collections::VecDeque,
    fmt::Write,
    io::{self, stdin},
};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (n, m) = (
        input.next().unwrap() as usize,
        input.next().unwrap() as usize,
    );
    let mut map = vec![vec![0; m]; n];
    let mut ans = vec![vec![-1; m]; n];
    let mut target_pos = (0, 0);
    for r in 0..n {
        for c in 0..m {
            map[r][c] = input.next().unwrap();
            match map[r][c] {
                0 => ans[r][c] = 0,
                2 => target_pos = (r, c),
                _ => (),
            }
        }
    }
    bfs(&target_pos, n, m, &map, &mut ans);
    let mut output = String::new();
    for r in ans.iter() {
        for count in r.iter() {
            write!(output, "{} ", count).unwrap();
        }
        writeln!(output).unwrap();
    }
    print!("{output}");
}

fn bfs(pos: &(usize, usize), n: usize, m: usize, map: &[Vec<i32>], ans: &mut [Vec<i32>]) {
    let mut q = VecDeque::new();
    ans[pos.0][pos.1] = 0;
    q.push_back((pos.0, pos.1, 0));
    while !q.is_empty() {
        let (r, c, count) = q.pop_front().unwrap();
        for i in 0..4 {
            let next_r = r as i32 + DR[i];
            let next_c = c as i32 + DC[i];
            if next_r >= 0
                && next_r < n as i32
                && next_c >= 0
                && next_c < m as i32
                && map[next_r as usize][next_c as usize] == 1
                && ans[next_r as usize][next_c as usize] == -1
            {
                ans[next_r as usize][next_c as usize] = count + 1;
                q.push_back((next_r as usize, next_c as usize, count + 1));
            }
        }
    }
}