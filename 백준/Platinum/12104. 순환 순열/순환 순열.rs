use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let (mut a, b) = (
        input.next().unwrap().repeat(2),
        input.next().unwrap().to_string(),
    );
    a.pop();
    print!("{}", kmp(&a, &b).len());
}

fn kmp(data: &String, query: &String) -> Vec<usize> {
    let data_bytes = data.as_bytes();
    let pi = get_pi(query);
    let mut matched_indexes = Vec::new();
    let mut j = 0;
    let query_bytes = query.as_bytes();
    for (i, &byte) in data_bytes.iter().enumerate() {
        while j > 0 && byte != query_bytes[j] {
            j = pi[j - 1];
        }
        if byte == query_bytes[j] {
            j += 1;
        }
        if j == query_bytes.len() {
            let idx: usize = (i as i32 - j as i32 + 1) as usize;
            matched_indexes.push(idx);
            j = pi[j - 1];
        }
    }
    matched_indexes
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