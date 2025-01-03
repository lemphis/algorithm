use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut chars = input.next().unwrap().chars().collect::<Vec<char>>();
    let one_count = chars.iter().filter(|&&c| c == '1').count();
    let (mut delete_count, mut idx) = (one_count / 2, 0);
    while delete_count > 0 {
        if chars[idx] == '1' {
            chars[idx] = 'X';
            delete_count -= 1;
        }
        idx += 1;
    }
    (delete_count, idx) = ((chars.len() - one_count) / 2, chars.len() - 1);
    while delete_count > 0 {
        if chars[idx] == '0' {
            chars[idx] = 'X';
            delete_count -= 1;
        }
        idx -= 1;
    }
    print!(
        "{}",
        chars
            .iter()
            .collect::<String>()
            .split("X")
            .collect::<String>()
    );
}