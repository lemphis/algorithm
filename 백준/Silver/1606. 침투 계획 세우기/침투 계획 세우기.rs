use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let (x, y) = {
        let mut it = input.split_ascii_whitespace().flat_map(str::parse::<u64>);
        (it.next().unwrap(), it.next().unwrap())
    };
    let mut ans = 1;
    for i in 1..(x + y) {
        ans += 6 * i;
    }
    if y > 0 {
        ans += y;
    }
    print!("{}", ans);
}