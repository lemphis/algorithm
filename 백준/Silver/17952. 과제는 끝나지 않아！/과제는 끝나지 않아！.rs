use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut stack = Vec::new();
    let mut score = 0;
    for _ in 0..n {
        let is_assignment = f() == 1;
        if is_assignment {
            let (a, t) = (f(), f());
            stack.push((a, t));
        }
        if !stack.is_empty() {
            let len = stack.len();
            stack[len - 1].1 -= 1;
            if stack[len - 1].1 == 0 {
                score += stack.pop().unwrap().0;
            }
        }
    }
    print!("{score}");
}