use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut scores = (0..n).map(|_| (f(), f())).collect::<Vec<_>>();
    scores.sort_by(|a, b| {
        if a.0 == b.0 {
            a.1.cmp(&b.1)
        } else {
            b.0.cmp(&a.0)
        }
    });
    print!(
        "{}",
        scores
            .iter()
            .skip(5)
            .filter(|(count, _)| *count == scores[4].0)
            .count()
    );
}