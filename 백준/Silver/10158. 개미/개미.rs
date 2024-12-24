use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (w, h, p, q, t) = (f(), f(), f(), f(), f());
    print!(
        "{} {}",
        w - w.abs_diff((p + t) % (w * 2)),
        h - h.abs_diff((q + t) % (h * 2))
    );
}