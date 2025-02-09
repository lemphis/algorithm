use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (a, b, c) = (f(), f(), f());
    let next_index = if let Ok(n) = c.parse::<usize>() {
        n + 1
    } else if let Ok(n) = b.parse::<usize>() {
        n + 2
    } else if let Ok(n) = a.parse::<usize>() {
        n + 3
    } else {
        unreachable!();
    };

    print!("{}", fizz_buzz(next_index));
}

fn fizz_buzz(i: usize) -> String {
    match (i % 3 == 0, i % 5 == 0) {
        (true, true) => "FizzBuzz".to_string(),
        (true, false) => "Fizz".to_string(),
        (false, true) => "Buzz".to_string(),
        (false, false) => i.to_string(),
    }
}