use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let (mut j, n) = (input.next().unwrap(), input.next().unwrap());
        let mut boxes = vec![0; n];
        for b in boxes.iter_mut() {
            *b = input.next().unwrap() * input.next().unwrap();
        }
        boxes.sort_unstable();
        let mut idx = n - 1;
        while j > boxes[idx] {
            j -= boxes[idx];
            idx -= 1;
        }
        writeln!(output, "{}", n - idx).unwrap();
    }
    print!("{output}");
}