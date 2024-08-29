use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<f64>);
    let _ = input.next().unwrap() as usize;
    let mut scores = input.collect::<Vec<_>>();
    scores.sort_unstable_by(|a, b| a.partial_cmp(b).unwrap());
    scores.iter().take(7).for_each(|score| println!("{:.3}", score));
}