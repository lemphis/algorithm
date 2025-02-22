use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let paper: Vec<Vec<_>> = (0..n).map(|_| (0..m).map(|_| f()).collect()).collect();

    let poses = [
        [(0, 0), (1, 0), (2, 0), (3, 0)],
        [(0, 0), (0, 1), (0, 2), (0, 3)],
        [(0, 0), (1, 0), (0, 1), (1, 1)],
        [(0, 0), (0, -1), (-1, -1), (-2, -1)],
        [(0, 0), (-1, 0), (-1, 1), (-1, 2)],
        [(0, 0), (0, 1), (1, 1), (2, 1)],
        [(0, 0), (1, 0), (1, -1), (1, -2)],
        [(0, 0), (0, 1), (-1, 1), (-2, 1)],
        [(0, 0), (-1, 0), (-1, -1), (-1, -2)],
        [(0, 0), (0, -1), (1, -1), (2, -1)],
        [(0, 0), (1, 0), (1, 1), (1, 2)],
        [(0, 0), (-1, 0), (1, 0), (0, -1)],
        [(0, 0), (-1, 0), (1, 0), (0, 1)],
        [(0, 0), (0, -1), (0, 1), (-1, 0)],
        [(0, 0), (0, -1), (0, 1), (1, 0)],
        [(0, 0), (1, 0), (1, 1), (2, 1)],
        [(0, 0), (0, -1), (1, -1), (1, -2)],
        [(0, 0), (-1, 0), (-1, -1), (-2, -1)],
        [(0, 0), (0, 1), (-1, 1), (-1, 2)],
        [(0, 0), (1, 0), (1, -1), (2, -1)],
        [(0, 0), (0, -1), (-1, -1), (-1, -2)],
        [(0, 0), (-1, 0), (-1, 1), (-2, 1)],
        [(0, 0), (0, 1), (1, 1), (1, 2)],
    ];

    let mut max_sum = 0;
    for r in 0..n {
        for c in 0..m {
            for d in poses {
                let (mut sum, mut valid) = (0, true);
                for (dr, dc) in d {
                    if dr + r as i32 >= 0
                        && (dr + r as i32) < n as i32
                        && dc + c as i32 >= 0
                        && (dc + c as i32) < m as i32
                    {
                        sum += paper[(r as i32 + dr) as usize][(c as i32 + dc) as usize];
                    } else {
                        valid = false;
                        break;
                    }
                }
                if valid {
                    max_sum = max_sum.max(sum);
                }
            }
        }
    }
    print!("{max_sum}");
}