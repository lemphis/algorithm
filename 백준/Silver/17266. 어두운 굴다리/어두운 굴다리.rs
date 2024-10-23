use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (n, m) = (input.next().unwrap(), input.next().unwrap());
    let pos = input.take(m).collect::<Vec<_>>();
    let mut d = vec![0; m + 1];
    d[0] = pos[0];
    for i in 1..m {
        d[i] = ((pos[i] - pos[i - 1]) as f64 / 2.0).ceil() as usize;
    }
    d[m] = n - pos[m - 1];
    print!("{}", d.iter().max().unwrap());
}