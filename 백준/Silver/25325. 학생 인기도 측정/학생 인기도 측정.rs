use std::{
    collections::HashMap,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next();
    let n = f().unwrap().parse::<usize>().unwrap();
    let mut map = HashMap::new();
    for _ in 0..n {
        map.entry(f().unwrap()).or_default();
    }

    while let Some(name) = f() {
        map.entry(name).and_modify(|e| {
            *e += 1;
        });
    }

    let mut vec: Vec<(&str, i32)> = map.iter().map(|(k, v)| (*k, *v)).collect();
    vec.sort_by(|a, b| {
        if a.1 == b.1 {
            a.0.cmp(b.0)
        } else {
            b.1.cmp(&a.1)
        }
    });

    let mut output = String::with_capacity(1024);
    for (name, count) in vec {
        output.push_str(&format!("{name} {count}\n"));
    }

    print!("{output}");
}