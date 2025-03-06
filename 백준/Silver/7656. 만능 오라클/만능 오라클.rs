use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    input
        .trim()
        .split_inclusive(|c| c == '.' || c == '?')
        .map(|s| s.trim())
        .filter(|s| s.ends_with('?') && s.starts_with("What is"))
        .for_each(|q| {
            let answer = format!("Forty-two{}.", &q[4..q.len() - 1]);
            println!("{}", answer);
        });
}