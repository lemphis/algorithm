use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(64);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let (a1, a0, c, n0) = (f(), f(), f(), f());
    print!(
        "{}",
        if a1 * n0 + a0 <= c * n0 && a1 <= c {
            1
        } else {
            0
        }
    );
}