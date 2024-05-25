use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut items = Vec::with_capacity(n);
    for _ in 0..n {
        items.push(input.next().unwrap().to_string());
    }
    items.sort_by_key(|a| a.len());
    let mut ans = n;
    for i in 0..n {
        for j in i + 1..n {
            if items[j].starts_with(&items[i]) {
                ans -= 1;
                break;
            }
        }
    }
    print!("{}", ans);
}
