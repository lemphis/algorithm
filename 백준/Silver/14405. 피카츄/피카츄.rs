use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut s = buf.split_ascii_whitespace().next().unwrap();
    let chars = ["pi", "ka", "chu"];
    let mut is_match = true;
    while !s.is_empty() && is_match {
        is_match = false;
        for &c in chars.iter() {
            if s.starts_with(c) {
                s = &s[c.len()..];
                is_match = true;
                break;
            }
        }
    }
    print!("{}", if s.is_empty() { "YES" } else { "NO" });
}