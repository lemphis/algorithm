use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let poses = (0..n).map(|_| (f(), f())).collect::<Vec<_>>();
    let diffs = (0..n - 1)
        .map(|i| (poses[i].0 - poses[i + 1].0).abs() + (poses[i].1 - poses[i + 1].1).abs())
        .collect::<Vec<_>>();
    let diffs_sum = diffs.iter().sum::<i32>();
    let mut diffs_min_sum = diffs_sum;
    for (i, &(x, y)) in poses.iter().take(n - 2).enumerate() {
        diffs_min_sum = diffs_min_sum.min(
            diffs_sum - diffs[i] - diffs[i + 1]
                + (poses[i + 2].0 - x).abs()
                + (poses[i + 2].1 - y).abs(),
        );
    }
    print!("{diffs_min_sum}");
}