use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let (s, t) = (input.next().unwrap(), input.next().unwrap());
    let gcd = gcd(s.len(), t.len());
    let repeat_s = s.repeat(t.len() / gcd);
    let repeat_t = t.repeat(s.len() / gcd);
    print!("{}", if repeat_s == repeat_t { 1 } else { 0 });
}

fn gcd(a: usize, b: usize) -> usize {
    if a % b == 0 {
        b
    } else {
        gcd(b, a % b)
    }
}