use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (a, b, c) = (f(), f(), f());
    if let Ok(n) = a.parse::<usize>() {
        print!("{}", fizz_buzz(n + 3));
        return;
    }
    if let Ok(n) = b.parse::<usize>() {
        print!("{}", fizz_buzz(n + 2));
        return;
    }
    if let Ok(n) = c.parse::<usize>() {
        print!("{}", fizz_buzz(n + 1));
        return;
    }
}

fn fizz_buzz(i: usize) -> String {
    match i {
        i if i % 3 == 0 && i % 5 != 0 => String::from("Fizz"),
        i if i % 3 != 0 && i % 5 == 0 => String::from("Buzz"),
        i if i % 3 == 0 && i % 5 == 0 => String::from("FizzBuzz"),
        i => i.to_string(),
    }
}