use std::io::{self};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut line = input.split_ascii_whitespace();
    let mut str = line.next().unwrap().to_string();
    let mut sum = 0;
    if str.len() == 1 {
        sum = str.parse::<u32>().unwrap();
    }
    let mut cnt = 0;
    while str.len() > 1 {
        sum = 0;
        for ch in str.chars() {
            sum += ch.to_digit(10).unwrap();
        }
        str = sum.to_string();
        cnt += 1;
    }
    print!("{}\n{}", cnt, if sum % 3 == 0 { "YES" } else { "NO" });
}