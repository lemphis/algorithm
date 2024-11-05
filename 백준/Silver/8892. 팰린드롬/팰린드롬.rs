use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let t = input.next().unwrap().parse::<usize>().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let strs = (0..n).map(|_| input.next().unwrap()).collect::<Vec<_>>();
        output.push_str(&format!("{}\n", is_palindrome(strs)));
    }
    print!("{output}");
}

fn is_palindrome(strs: Vec<&str>) -> String {
    for (i, &left) in strs.iter().enumerate() {
        for &right in strs.iter().take(i) {
            let mut new_str = String::from(left);
            new_str.push_str(right);
            if check(&new_str) {
                return new_str;
            }
            let mut new_str = String::from(right);
            new_str.push_str(left);
            if check(&new_str) {
                return new_str;
            }
        }
    }
    String::from("0")
}

fn check(s: &str) -> bool {
    let pivot = s.len() / 2;
    let chars = s.chars().collect::<Vec<_>>();
    for i in 0..pivot {
        if chars[i] != chars[s.len() - i - 1] {
            return false;
        }
    }
    true
}