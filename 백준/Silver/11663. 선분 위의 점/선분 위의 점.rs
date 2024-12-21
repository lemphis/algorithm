use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut points = (0..n).map(|_| f()).collect::<Vec<_>>();
    points.sort_unstable();
    let mut output = String::new();
    for _ in 0..m {
        let (start, end) = (f(), f());
        let lower = points.partition_point(|&x| x < start);
        let upper = points.partition_point(|&x| x <= end);
        output.push_str(&format!("{}\n", upper - lower));
    }
    print!("{output}");
}