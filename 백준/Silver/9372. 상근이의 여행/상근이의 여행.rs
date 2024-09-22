use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let (n, m) = (input.next().unwrap(), input.next().unwrap());
        writeln!(output, "{}", n - 1).unwrap();
        input.nth(m * 2 - 1);
    }
    print!("{output}");
}