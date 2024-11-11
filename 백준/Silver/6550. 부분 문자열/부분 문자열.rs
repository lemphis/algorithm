use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next();
    let mut output = String::new();
    while let (Some(s), Some(t)) = (f(), f()) {
        let mut idx = 0;
        let s_chars = s.chars().collect::<Vec<_>>();
        for c in t.chars() {
            if c == s_chars[idx] {
                idx += 1;
            }
            if idx == s.len() {
                break;
            }
        }
        output.push_str(&format!("{}\n", if idx == s.len() { "Yes" } else { "No" }));
    }
    print!("{output}");
}