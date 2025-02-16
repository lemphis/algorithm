use std::{
    collections::VecDeque,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::with_capacity(1024 * 1024);
    for _ in 0..t {
        let (a, b) = (f(), f());
        let mut q = VecDeque::new();
        q.push_back(a);
        let mut parent = [(0, None); 10_000];
        while let Some(num) = q.pop_front() {
            if num == b {
                let (mut idx, mut commands) = (num, Vec::with_capacity(1024));
                while a != idx {
                    commands.push(parent[idx].1.unwrap());
                    idx = parent[idx].0;
                }
                for c in commands.into_iter().rev() {
                    output.push_str(c);
                }
                output.push('\n');
                break;
            }
            let (d, s, l, r) = (
                num * 2 % 10000,
                if num == 0 { 9999 } else { num - 1 },
                num % 1000 * 10 + num / 1000,
                num % 10 * 1000 + (num - num % 10) / 10,
            );
            if parent[d].1.is_none() {
                q.push_back(d);
                parent[d] = (num, Some("D"));
            }
            if parent[s].1.is_none() {
                q.push_back(s);
                parent[s] = (num, Some("S"));
            }
            if parent[l].1.is_none() {
                q.push_back(l);
                parent[l] = (num, Some("L"));
            }
            if parent[r].1.is_none() {
                q.push_back(r);
                parent[r] = (num, Some("R"));
            }
        }
    }
    print!("{output}");
}