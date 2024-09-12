use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let num = input.next().unwrap();
        let mut is_same = false;
        for base in 2..=64 {
            if is_palindrome_in_base(num, base) {
                is_same = true;
                break;
            }
        }
        writeln!(output, "{}", if is_same { 1 } else { 0 }).unwrap();
    }
    print!("{output}");
}

fn is_palindrome_in_base(mut num: usize, base: usize) -> bool {
    let mut digits = Vec::new();
    while num > 0 {
        digits.push(num % base);
        num /= base;
    }
    let len = digits.len();
    for i in 0..len / 2 {
        if digits[i] != digits[len - 1 - i] {
            return false;
        }
    }
    true
}