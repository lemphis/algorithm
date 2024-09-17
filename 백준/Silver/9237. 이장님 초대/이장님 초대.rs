use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut seedlings = input.skip(1).collect::<Vec<_>>();
    seedlings.sort_unstable_by(|a, b| b.cmp(a));
    print!("{}", seedlings.iter().enumerate().map(|(i, seedling)| i + seedling).max().unwrap() + 2);
}