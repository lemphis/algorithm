use std::io;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    input.pop();
    let mut query = String::new();
    let _ = io::stdin().read_line(&mut query);
    query.pop();
    let match_indexes = kmp(&input, &query);
    let mut output = String::new();
    output.push_str(&format!("{}\n", match_indexes.len()));
    for idx in match_indexes {
        output.push_str(&format!("{} ", idx + 1));
    }
    print!("{output}");
}

fn kmp(data: &str, query: &str) -> Vec<usize> {
    let data_bytes = data.as_bytes();
    let query_bytes = query.as_bytes();
    let pi = get_pi(query);
    let mut match_indexes = Vec::new();
    let mut j = 0;
    for (i, &byte) in data_bytes.iter().enumerate() {
        while j > 0 && byte != query_bytes[j] {
            j = pi[j - 1];
        }
        if byte == query_bytes[j] {
            j += 1;
        }
        if j == query.len() {
            let idx: usize = (i as i32 - j as i32 + 1) as usize;
            match_indexes.push(idx);
            j = pi[j - 1];
        }
    }
    match_indexes
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
        }
        v[i] = j;
    }
    v
}