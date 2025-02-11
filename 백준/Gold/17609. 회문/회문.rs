use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();

    let mut output = String::with_capacity(n * 2);
    for _ in 0..n {
        let chars: Vec<char> = f().chars().collect();
        let (mut l, mut r, mut removed, mut is_palindrome) = (0, chars.len() - 1, false, true);
        while l < r {
            if chars[l] != chars[r] {
                is_palindrome =
                    check_palindrome(&chars[l + 1..=r]) || check_palindrome(&chars[l..=r - 1]);
                removed = true;
                break;
            } else {
                l += 1;
                r -= 1;
            }
        }
        output.push_str(&format!(
            "{}\n",
            match (is_palindrome, removed) {
                (true, false) => 0,
                (true, true) => 1,
                (false, _) => 2,
            }
        ));
    }
    print!("{output}");
}

fn check_palindrome(chars: &[char]) -> bool {
    let len = chars.len();
    for i in 0..len / 2 {
        if chars[i] != chars[len - 1 - i] {
            return false;
        }
    }
    true
}