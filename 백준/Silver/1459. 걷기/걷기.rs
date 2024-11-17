use std::{
    io::{self, stdin},
    mem::swap,
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (mut x, mut y, w, s) = (f(), f(), f(), f());
    if y > x {
        swap(&mut x, &mut y);
    }
    print!(
        "{}",
        if s >= w * 2 {
            (x + y) * w
        } else {
            y * s
                + if w < s {
                    (x - y) * w
                } else {
                    if (x - y) & 1 == 0 {
                        (x - y) * s
                    } else {
                        (x - y - 1) * s + w
                    }
                }
        }
    );
}