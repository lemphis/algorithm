use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let (a, b) = (input.next().unwrap(), input.next().unwrap());
    let min_diff = input.skip(1).collect::<Vec<_>>().iter().map(|it| (b - it).abs()).min().unwrap();
    let freq_diff = (b - a).abs();
    print!("{}", if min_diff < freq_diff {min_diff + 1} else {freq_diff});
}
