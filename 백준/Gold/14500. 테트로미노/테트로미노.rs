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

    let poses: [[(i32, i32); 4]; 19] = [
        [(0, 0), (0, 1), (0, 2), (0, 3)],
        [(0, 0), (1, 0), (2, 0), (3, 0)],
        [(0, 0), (0, 1), (1, 0), (1, 1)],
        [(0, 0), (1, 0), (2, 0), (2, 1)],
        [(0, 0), (0, 1), (0, 2), (1, 0)],
        [(0, 0), (0, 1), (1, 1), (2, 1)],
        [(0, 0), (0, 1), (0, 2), (-1, 2)],
        [(0, 0), (0, 1), (-1, 1), (-2, 1)],
        [(0, 0), (1, 0), (1, 1), (1, 2)],
        [(0, 0), (0, 1), (1, 0), (2, 0)],
        [(0, 0), (0, 1), (0, 2), (1, 2)],
        [(0, 0), (1, 0), (1, 1), (2, 1)],
        [(0, 0), (0, 1), (-1, 1), (-1, 2)],
        [(0, 0), (1, 0), (0, 1), (-1, 1)],
        [(0, 0), (0, 1), (1, 1), (1, 2)],
        [(0, 0), (0, 1), (0, 2), (1, 1)],
        [(0, 0), (0, 1), (-1, 1), (1, 1)],
        [(0, 0), (0, 1), (-1, 1), (0, 2)],
        [(0, 0), (1, 0), (2, 0), (1, 1)],
    ];

    let mut max_sum = 0;
    for r in 0..n {
        for c in 0..m {
            for d in poses {
                if let Some(sum) = d.iter().try_fold(0, |acc, &(dr, dc)| {
                    let nr = r as i32 + dr;
                    let nc = c as i32 + dc;
                    if (0..n as i32).contains(&nr) && (0..m as i32).contains(&nc) {
                        Some(acc + paper[nr as usize][nc as usize])
                    } else {
                        None
                    }
                }) {
                    max_sum = max_sum.max(sum);
                }
            }
        }
    }
    print!("{max_sum}");
}