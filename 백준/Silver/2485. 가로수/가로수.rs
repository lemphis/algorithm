use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let distances = input.collect::<Vec<_>>();
    let mut diffs = vec![0; n - 1];
    for i in 0..n - 1 {
        diffs[i] = distances[i + 1] - distances[i];
    }
    let gcd = diffs.iter().fold(diffs[0], |acc, &cur| gcd(acc, cur));
    print!("{}", (distances[n - 1] - distances[0]) / gcd + 1 - n);
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}