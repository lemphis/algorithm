use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let (x1, y1, x2, y2, x3, y3) = (f(), f(), f(), f(), f(), f());
    print!(
        "{}",
        ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)).signum()
    )
}