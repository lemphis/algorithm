use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let mut output = String::new();
    while let Some(s) = input.next() {
        if s == "." {
            break;
        }
        let &last = get_pi(s).last().unwrap();
        let dupe_len = s.len() - last;
        output.push_str(&format!(
            "{}\n",
            if s.len() % dupe_len == 0 {
                s.len() / dupe_len
            } else {
                1
            }
        ));
    }
    print!("{output}");
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