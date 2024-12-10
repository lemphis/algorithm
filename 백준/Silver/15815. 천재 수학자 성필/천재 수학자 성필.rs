use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let formula = input.next().unwrap();
    let mut stack = Vec::with_capacity(formula.len());
    for c in formula.chars() {
        if c.is_ascii_digit() {
            stack.push(c.to_digit(10).unwrap() as i32);
        } else {
            let mut p = || stack.pop().unwrap();
            let (r, l) = (p(), p());
            stack.push(match c {
                '*' => l * r,
                '/' => l / r,
                '+' => l + r,
                '-' => l - r,
                _ => unreachable!(),
            });
        }
    }
    print!("{}", stack.last().unwrap());
}