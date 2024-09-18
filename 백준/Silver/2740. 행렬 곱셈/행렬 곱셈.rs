use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let (n, m) = (
        input.next().unwrap() as usize,
        input.next().unwrap() as usize,
    );
    let mut left = vec![vec![0; m]; n];
    for r in left.iter_mut() {
        for c in r.iter_mut() {
            *c = input.next().unwrap();
        }
    }
    let (_, k) = (input.next().unwrap(), input.next().unwrap() as usize);
    let mut right = vec![vec![0; k]; m];
    for r in right.iter_mut() {
        for c in r.iter_mut() {
            *c = input.next().unwrap();
        }
    }
    let mut ans = vec![vec![0; k]; n];
    for r in 0..n {
        for c in 0..k {
            for i in 0..m {
                ans[r][c] += left[r][i] * right[i][c];
            }
        }
    }
    let mut output = String::new();
    for r in ans.iter() {
        for c in r.iter() {
            write!(output, "{} ", c).unwrap();
        }
        writeln!(output).unwrap();
    }
    print!("{output}");
}