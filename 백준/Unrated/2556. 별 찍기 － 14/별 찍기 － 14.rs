use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..n {
        for _ in 0..n {
            output.push('*');
        }
        output.push('\n');
    }
    print!("{output}");
}
