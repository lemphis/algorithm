use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let (_, mut l) = (input.next(), input.next().unwrap());
    let mut heights: Vec<usize> = input.collect();
    heights.sort_unstable();
    l = heights
        .iter()
        .fold(l, |acc, &cur| if cur > acc { acc } else { acc + 1 });
    print!("{l}");
}