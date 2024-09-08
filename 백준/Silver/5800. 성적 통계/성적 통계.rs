use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let k = input.next().unwrap();
    let mut output = String::new();
    for i in 0..k {
        writeln!(output, "Class {}", i + 1).unwrap();
        let n = input.next().unwrap();
        let mut scores = vec![0; n];
        for score in scores.iter_mut() {
            *score = input.next().unwrap();
        }
        scores.sort_unstable();
        writeln!(
            output,
            "Max {}, Min {}, Largest gap {}",
            scores[n - 1],
            scores[0],
            scores.windows(2).map(|w| w[1] - w[0]).max().unwrap()
        )
        .unwrap();
    }
    print!("{output}");
}