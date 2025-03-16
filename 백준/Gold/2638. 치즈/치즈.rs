use std::{
    collections::VecDeque,
    io::{self, BufReader, Read},
};

const DIR: [(i32, i32); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

fn main() {
    let mut buf = String::with_capacity(11000);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut paper: Vec<Vec<bool>> = (0..n).map(|_| (0..m).map(|_| f() == 1).collect()).collect();

    let mut count = 0;
    while !is_clear(&paper) {
        melt(&mut paper, n, m);
        count += 1;
    }

    print!("{count}");
}

fn is_clear(paper: &[Vec<bool>]) -> bool {
    paper.iter().all(|r| r.iter().all(|b| !*b))
}

fn melt(paper: &mut [Vec<bool>], n: usize, m: usize) {
    let mut q = VecDeque::with_capacity(100);
    q.push_back((0, 0));

    let mut visited = vec![vec![false; m]; n];
    visited[0][0] = true;

    let mut touch_count = vec![vec![0; m]; n];
    while let Some((r, c)) = q.pop_front() {
        for (dr, dc) in DIR {
            let (next_r, next_c) = (r + dr, c + dc);
            if (0..n as i32).contains(&next_r)
                && (0..m as i32).contains(&next_c)
                && !visited[next_r as usize][next_c as usize]
            {
                if paper[next_r as usize][next_c as usize] {
                    touch_count[next_r as usize][next_c as usize] += 1;
                } else {
                    visited[next_r as usize][next_c as usize] = true;
                    q.push_back((next_r, next_c));
                }
            }
        }
    }

    for r in 0..n {
        for c in 0..m {
            if touch_count[r][c] > 1 {
                paper[r][c] = false;
            }
        }
    }
}