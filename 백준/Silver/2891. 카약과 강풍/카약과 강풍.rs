use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, s, r) = (f(), f(), f());
    let mut teams = vec![1; n];
    for _ in 0..s {
        teams[f() - 1] -= 1;
    }
    for _ in 0..r {
        teams[f() - 1] += 1;
    }
    for i in 0..n {
        if teams[i] == 0 {
            if i as i32 - 1 >= 0 && teams[i - 1] > 1 {
                teams[i - 1] -= 1;
                teams[i] += 1;
                continue;
            }
            if i + 1 < n && teams[i + 1] > 1 {
                teams[i + 1] -= 1;
                teams[i] += 1;
            }
        }
    }
    print!("{}", teams.iter().filter(|&&num| num == 0).count());
}