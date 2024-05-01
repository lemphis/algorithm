use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut v = Vec::<String>::new();
    for _ in 0..n {
        let str = input.next().unwrap();
        let mut num = String::new();
        for ch in str.chars() {
            if ch.is_ascii_digit() {
                num.push(ch);
            } else if !num.is_empty() {
                let mut non_zero_idx = usize::MAX;
                for (i, c) in num.chars().enumerate() {
                    if c != '0' {
                        non_zero_idx = i;
                        break;
                    }
                }
                if non_zero_idx == usize::MAX {
                    v.push(String::from("0"));
                } else {
                    v.push(num[non_zero_idx..].to_string());
                }
                num = String::new();
            }
        }
        if !num.is_empty() {
            if num.starts_with('0') {
                let mut non_zero_idx = usize::MAX;
                for (i, c) in num.chars().enumerate() {
                    if c != '0' {
                        non_zero_idx = i;
                        break;
                    }
                }
                if non_zero_idx == usize::MAX {
                    v.push(String::from("0"));
                } else {
                    v.push(num[non_zero_idx..].to_string());
                }
            } else {
                v.push(num);
            }
        }
    }
    v.sort_by(|a, b| {
        if a.len() != b.len() {
            a.len().cmp(&b.len())
        } else {
            a.cmp(b)
        }
    });
    let mut output = String::new();
    for num in v {
        output.push_str(&format!("{num}\n"));
    }
    print!("{output}");
}
