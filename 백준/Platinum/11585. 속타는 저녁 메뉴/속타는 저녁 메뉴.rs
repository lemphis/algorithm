use std::io::{self};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    input.clear();
    let _ = io::stdin().read_line(&mut input);
    let win_str = input.split_ascii_whitespace().collect::<String>();
    input.clear();
    let _ = io::stdin().read_line(&mut input);
    let mut roulette = input.split_ascii_whitespace().collect::<String>().repeat(2);
    roulette.pop();
    let find_indexes = kmp(&roulette, &win_str);
    let gcd = gcd((roulette.len() / 2 + 1), find_indexes.len());
    print!(
        "{}/{}",
        find_indexes.len() / gcd,
        (roulette.len() / 2 + 1) / gcd
    );
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

fn get_pi(query: &String) -> Vec<usize> {
    let query_bytes = query.as_bytes();
    let mut v = vec![0; query_bytes.len()];
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

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}