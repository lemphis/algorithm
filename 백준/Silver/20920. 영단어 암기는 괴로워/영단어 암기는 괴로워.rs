use std::{
    collections::HashMap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let m = input.next().unwrap().parse::<usize>().unwrap();
    let mut map = HashMap::new();
    for _ in 0..n {
        let word = input.next().unwrap();
        if word.len() >= m {
            *map.entry(word).or_insert(0) += 1;
        }
    }
    let mut v = map.into_iter().collect::<Vec<(&str, i32)>>();
    v.sort_by(|a, b| {
        if a.1 == b.1 {
            if a.0.len() == b.0.len() {
                return a.0.cmp(b.0);
            }
            return b.0.len().cmp(&a.0.len());
        }
        b.1.cmp(&a.1)
    });
    let mut output = String::new();
    for (word, _) in v {
        output.push_str(&format!("{word}\n"));
    }
    print!("{output}");
}