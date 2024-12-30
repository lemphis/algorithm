use std::io::{self, stdin};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n = f().parse::<usize>().unwrap();
    let mut candies = (0..n)
        .map(|_| f().chars().collect::<Vec<_>>())
        .collect::<Vec<_>>();
    let mut max_count = 0;
    for r in 0..n {
        for c in 0..n {
            for i in 0..4 {
                let (next_r, next_c) = (r as i32 + DR[i], c as i32 + DC[i]);
                if is_in_bounds(next_r, next_c, n) {
                    self::swap(&mut candies, r, c, next_r as usize, next_c as usize);
                    let count = count_max_candies(&mut candies, r, c);
                    max_count = max_count.max(count);
                    self::swap(&mut candies, next_r as usize, next_c as usize, r, c);
                }
            }
        }
    }
    print!("{max_count}");
}

fn is_in_bounds(r: i32, c: i32, size: usize) -> bool {
    r >= 0 && (r as usize) < size && c >= 0 && (c as usize) < size
}

fn swap(adj: &mut [Vec<char>], src_r: usize, src_c: usize, dest_r: usize, dest_c: usize) {
    let temp = adj[src_r][src_c];
    adj[src_r][src_c] = adj[dest_r][dest_c];
    adj[dest_r][dest_c] = temp;
}

fn count_max_candies(adj: &mut [Vec<char>], r: usize, c: usize) -> usize {
    let (mut max_count, mut count) = (0, 1);
    for c in 1..adj[r].len() {
        if adj[r][c] == adj[r][c - 1] {
            count += 1;
        } else {
            max_count = max_count.max(count);
            count = 1;
        }
    }
    max_count = max_count.max(count);
    count = 1;
    for r in 1..adj.len() {
        if adj[r][c] == adj[r - 1][c] {
            count += 1;
        } else {
            max_count = max_count.max(count);
            count = 1;
        }
    }
    max_count = max_count.max(count);

    max_count
}