use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut next = || input.next().unwrap();

    let n = next() as usize;
    let poses = (0..n).map(|_| (next(), next())).collect::<Vec<_>>();

    let mut total_distance = 0;
    let mut diffs = vec![0; n - 1];

    for i in 0..n - 1 {
        let dist = (poses[i].0 - poses[i + 1].0).abs() + (poses[i].1 - poses[i + 1].1).abs();
        diffs[i] = dist;
        total_distance += dist;
    }

    let mut min_distance = total_distance;

    for i in 0..n - 2 {
        let skip_original = diffs[i] + diffs[i + 1];
        let skip_new = (poses[i].0 - poses[i + 2].0).abs() + (poses[i].1 - poses[i + 2].1).abs();
        min_distance = min_distance.min(total_distance - skip_original + skip_new);
    }

    println!("{}", min_distance);
}