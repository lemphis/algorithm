use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    while let Some(n) = it.next() {
        let n = n.parse::<u32>().unwrap();
        let len = 3_u32.pow(n);
        let s = "-".repeat(len as usize);
        println!("{}", process(&s));
    }
}

fn process(s: &str) -> String {
    if s.len() == 1 {
        s.to_string()
    } else {
        let sub_len = s.len() / 3;
        format!(
            "{}{}{}",
            process(&s[..sub_len]),
            " ".repeat(sub_len).as_str(),
            process(&s[sub_len * 2..])
        )
    }
}