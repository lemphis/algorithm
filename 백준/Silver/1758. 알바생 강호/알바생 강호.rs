use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut tips = input.skip(1).collect::<Vec<_>>();
    tips.sort_unstable_by(|a, b| b.cmp(a));
    print!(
        "{}",
        tips.iter()
            .enumerate()
            .fold(0, |acc, (i, tip)| acc + tip.saturating_sub(i))
    );
}