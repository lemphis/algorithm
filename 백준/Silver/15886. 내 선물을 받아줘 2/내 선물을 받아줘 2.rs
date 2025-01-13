use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (_, s) = (f().parse::<usize>().unwrap(), f());
    let mut count = 0;
    let chars = s.chars().collect::<Vec<_>>();
    for (i, &c) in chars.iter().enumerate().skip(1) {
        if c == 'W' && chars[i - 1] == 'E' {
            count += 1;
        }
    }
    print!("{count}");
}