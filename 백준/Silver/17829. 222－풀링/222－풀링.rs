use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let matrix: Vec<Vec<i32>> = (0..n).map(|_| (0..n).map(|_| f()).collect()).collect();
    print!("{}", find(&matrix, 0, 0, matrix.len()));
}

fn find(matrix: &[Vec<i32>], r: usize, c: usize, size: usize) -> i32 {
    if size == 1 {
        return matrix[r][c];
    }
    let mut v = [
        find(matrix, r, c, size / 2),
        find(matrix, r + size / 2, c, size / 2),
        find(matrix, r, c + size / 2, size / 2),
        find(matrix, r + size / 2, c + size / 2, size / 2),
    ];
    v.sort_unstable();
    v[2]
}