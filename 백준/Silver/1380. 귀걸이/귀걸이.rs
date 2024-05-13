use std::io::{self};

fn main() {
    let mut tc = 1;
    loop {
        let mut input = String::new();
        let _ = io::stdin().read_line(&mut input);
        let n = input
            .split_ascii_whitespace()
            .next()
            .unwrap()
            .parse::<usize>()
            .unwrap();
        if n == 0 {
            break;
        }
        let mut v = vec![(String::new(), 0); n];
        for i in 0..n {
            let mut input = String::new();
            let _ = io::stdin().read_line(&mut input);
            v[i].0 = input.trim().to_string();
        }
        for _ in 0..(n * 2 - 1) {
            let mut input = String::new();
            let _ = io::stdin().read_line(&mut input);
            let mut split = input.split_ascii_whitespace();
            let idx = split.next().unwrap().parse::<usize>().unwrap();
            let _ = split.next().unwrap();
            v[idx - 1].1 += 1;
        }
        for (name, cnt) in v {
            if cnt < 2 {
                println!("{tc} {name}");
                break;
            }
        }
        tc += 1;
    }
}