use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace();
    let (n, m, s) = (
        it.next().unwrap().parse::<usize>().unwrap(),
        it.next().unwrap().parse::<usize>().unwrap(),
        it.next().unwrap(),
    );
    let mut idx = 0;
    let mut count = 0;
    let mut ans = 0;
    while idx < m - 2 {
        if &s[idx..idx + 3] == "IOI" {
            count += 1;
            idx += 2;
            if count >= n {
                ans += 1;
            }
        } else {
            count = 0;
            idx += 1;
        }
    }

    print!("{ans}");
}