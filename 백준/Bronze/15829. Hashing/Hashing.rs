use std::io::{self, stdin};

const DIV: usize = 1_234_567_891;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (_, s) = (f(), f());
    let chars: Vec<char> = s.chars().collect();
    let mut ans = 0;
    for (i, c) in chars.iter().enumerate() {
        let mut sum = (*c as u8 - b'a' + 1) as usize;
        for _ in 1..=i {
            sum = (sum * 31) % DIV;
        }
        ans = (ans + sum) % DIV;
    }
    print!("{ans}");
}