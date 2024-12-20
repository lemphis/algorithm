use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let m = f();
    let (mut sum_result, mut xor_result) = (0, 0);
    let mut output = String::new();
    for _ in 0..m {
        match f() {
            1 => {
                let num = f();
                sum_result += num;
                xor_result ^= num;
            }
            2 => {
                let num = f();
                sum_result -= num;
                xor_result ^= num;
            }
            3 => output.push_str(&format!("{sum_result}\n")),
            4 => output.push_str(&format!("{xor_result}\n")),
            _ => unreachable!(),
        }
    }
    print!("{output}");
}