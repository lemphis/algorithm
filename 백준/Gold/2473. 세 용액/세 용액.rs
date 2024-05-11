use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let n = input.next().unwrap() as usize;
    let mut v = vec![0; n];
    for i in 0..n {
        v[i] = input.next().unwrap();
    }
    v.sort();
    let mut min = i64::MAX;
    let mut min_indexes = (0, 0, 0);
    for i in 0..n - 1 {
        for j in i + 1..n {
            let mut lo = i;
            let mut hi = j;
            while lo + 1 < hi {
                let mid = (lo + hi) / 2;
                let sum = v[i] + v[mid] + v[j];
                if sum > 0 {
                    hi = mid;
                } else if sum < 0 {
                    lo = mid;
                } else {
                    print!("{} {} {}", v[i], v[mid], v[j]);
                    return;
                }
                if min.abs() > sum.abs() {
                    min = sum;
                    min_indexes = (i, mid, j);
                }
            }
        }
    }
    print!(
        "{} {} {}",
        v[min_indexes.0], v[min_indexes.1], v[min_indexes.2]
    );
}