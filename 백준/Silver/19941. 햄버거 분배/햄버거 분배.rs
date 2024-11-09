use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, k) = (f().parse::<i32>().unwrap(), f().parse::<i32>().unwrap());
    let mut table = f().chars().map(|c| (c, false)).collect::<Vec<_>>();
    let mut count = 0;
    for i in 0..n {
        if table[i as usize].0 == 'P' {
            for j in 0.max(i - k)..n.min(i + k + 1) {
                if table[j as usize] == ('H', false) {
                    table[i as usize].1 = true;
                    table[j as usize].1 = true;
                    count += 1;
                    break;
                }
            }
        }
    }
    print!("{count}");
}