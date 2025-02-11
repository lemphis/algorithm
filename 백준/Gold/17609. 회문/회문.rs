use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();

    let mut output = String::with_capacity(n * 2);
    for _ in 0..n {
        let chars: Vec<char> = f().chars().collect();
        output.push_str(&format!("{}\n", classify(&chars)));
    }
    print!("{output}");
}

fn classify(chars: &[char]) -> u8 {
    let (mut l, mut r) = (0, chars.len() - 1);
    while l < r {
        if chars[l] != chars[r] {
            return if check_palindrome(&chars[l + 1..=r]) || check_palindrome(&chars[l..=r - 1]) {
                1
            } else {
                2
            };
        }
        l += 1;
        r -= 1;
    }
    0
}

fn check_palindrome(chars: &[char]) -> bool {
    chars.iter().eq(chars.iter().rev())
}