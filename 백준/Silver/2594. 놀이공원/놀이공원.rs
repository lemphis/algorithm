use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut time = [false; 60 * 12];
    for _ in 0..n {
        let (mut from, mut to) = (f(), f());
        (from, to) = (
            (from / 100 * 60 + from % 100 - 600).saturating_sub(10),
            (to / 100 * 60 + to % 100 - 600 + 10).min(60 * 12),
        );
        for i in from..to {
            time[i] = true;
        }
    }
    let (mut max_len, mut len) = (0, 0);
    for &b in time.iter() {
        if b {
            max_len = max_len.max(len);
            len = 0;
        } else {
            len += 1;
        }
    }
    print!("{}", max_len.max(len));
}