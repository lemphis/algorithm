use std::io::{self};

fn main() {
    let bracket_pairs = [('(', ')'), ('{', '}'), ('[', ']')];
    let mut is_pair;
    let mut output = String::new();
    loop {
        is_pair = true;
        let mut v = Vec::new();
        let mut input = String::new();
        let _ = io::stdin().read_line(&mut input).unwrap();
        let input = input.trim();
        if input == "#" {
            break;
        }
        for ch in input.chars() {
            for (open, close) in bracket_pairs {
                if ch == open {
                    v.push(ch);
                }
                if ch == close {
                    if v.is_empty() || *v.last().unwrap() != open {
                        is_pair = false;
                        break;
                    } else {
                        v.pop();
                    }
                }
            }
            if !is_pair {
                break;
            }
        }
        output.push_str(&format!(
            "{}\n",
            if is_pair && v.is_empty() {
                "Legal"
            } else {
                "Illegal"
            }
        ));
    }
    print!("{output}");
}
