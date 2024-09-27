use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    if n == 0 {
        print!("0");
        return;
    }
    let exclude_count = (n as f64 * 0.15).round() as usize;
    let mut levels = input.collect::<Vec<_>>();
    levels.sort_unstable();
    print!(
        "{}",
        (levels
            .into_iter()
            .skip(exclude_count)
            .take(n - exclude_count * 2)
            .sum::<usize>() as f64
            / (n - exclude_count * 2) as f64)
            .round()
    );
}