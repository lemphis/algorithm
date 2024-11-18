use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let (n, x) = (f() as usize, f() as usize);
    let visitors = (0..n).map(|_| f()).collect::<Vec<_>>();
    let mut sum = visitors.iter().take(x).sum::<i32>();
    let mut sums = Vec::with_capacity(n - x + 1);
    sums.push(sum);
    for i in x..n {
        sum = sum - visitors[i - x] + visitors[i];
        sums.push(sum);
    }
    sums.sort_by(|a, b| b.cmp(a));
    if sums[0] == 0 {
        print!("SAD")
    } else {
        print!(
            "{}\n{}",
            sums[0],
            sums.iter().filter(|&&s| s == sums[0]).count()
        )
    };
}