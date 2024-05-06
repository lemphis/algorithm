use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let _ = input.next();
    let word = input.next().unwrap();
    let pi = get_pi(word);
    print!("{}", &format!("{}", word.len() - pi.last().unwrap()));
}

fn get_pi(query: &str) -> Vec<usize> {
    let len = query.len();
    let query_bytes = query.as_bytes();
    let mut v = vec![0; len];
    let mut j = 0;
    for (i, &byte) in query_bytes.iter().enumerate().skip(1) {
        while j > 0 && byte != query_bytes[j] {
            j = v[j - 1];
        }
        if byte == query_bytes[j] {
            j += 1;
            v[i] = j;
        }
    }
    v
}