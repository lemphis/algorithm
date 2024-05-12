use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (mut a, b, n) = (
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
    );
    let mut ans = 0;
    if a >= b {
        a %= b;
    }
    for _ in 0..n {
        a *= 10;
        ans = a / b;
        a %= b;
    }
    print!("{}", ans);
}