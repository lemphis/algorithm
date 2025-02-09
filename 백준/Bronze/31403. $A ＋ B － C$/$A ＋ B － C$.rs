use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let (a, b, c) = (f(), f(), f());
    print!(
        "{}\n{}",
        a + b - c,
        format!("{}{}", a, b).parse::<i32>().unwrap() - c
    );
}