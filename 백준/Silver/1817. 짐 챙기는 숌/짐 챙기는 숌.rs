use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let weights = (0..n).map(|_| f()).collect::<Vec<_>>();
    let (mut box_weight, mut count) = (m, 0);
    for &weight in weights.iter() {
        if box_weight + weight <= m {
            box_weight += weight;
        } else {
            box_weight = weight;
            count += 1;
        }
    }
    print!("{count}");
}