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
            let mut temp_is_same = true;
            let converted = to_base_n(num, base).chars().collect::<Vec<_>>();
            for i in 0..converted.len() / 2 {
                if converted[i] != converted[converted.len() - 1 - i] {
                    temp_is_same = false;
                    break;
                }
            }
            if temp_is_same {
                is_same = true;
                break;
            }
        }
        writeln!(output, "{}", if is_same { 1 } else { 0 }).unwrap();
    }
    print!("{output}");
}

fn to_base_n(num: usize, base: usize) -> String {
    let mut converted = Vec::new();
    let mut temp = num;
    while temp > 0 {
        converted.push(b'0' + (temp % base) as u8);
        temp /= base;
    }
    converted.reverse();
    String::from_utf8(converted).unwrap()
}