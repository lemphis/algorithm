use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let formula = input.next().unwrap().chars();
    let mut stack = Vec::with_capacity(formula.clone().count());
    for c in formula {
        if c.is_ascii_digit() {
            stack.push(c.to_digit(10).unwrap() as i32);
        } else {
            let (right, left) = (stack.pop().unwrap(), stack.pop().unwrap());
            stack.push(match c {
                '*' => left * right,
                '/' => left / right,
                '+' => left + right,
                '-' => left - right,
                _ => unreachable!(),
            });
        }
    }
    print!("{}", stack.last().unwrap());
}