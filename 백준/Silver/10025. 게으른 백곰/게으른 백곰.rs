use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let mut poses = (0..n).map(|_| (f(), f())).collect::<Vec<_>>();
    poses.sort_unstable_by(|a, b| a.1.cmp(&b.1));
    let (mut l, mut r, mut sum, mut max_sum) = (0, 0, 0, 0);
    while r < poses.len() && poses[r].1 < k * 2 {
        sum += poses[r].0;
        r += 1;
    }
    max_sum = max_sum.max(sum);
    for i in k + 1..poses.last().unwrap().1.saturating_sub(k) {
        if r == poses.len() {
            break;
        }
        if poses[l].1 < i - k {
            sum -= poses[l].0;
            l += 1;
        }
        if poses[r].1 <= i + k {
            sum += poses[r].0;
            r += 1;
        }
        max_sum = max_sum.max(sum);
    }
    print!("{max_sum}");
}