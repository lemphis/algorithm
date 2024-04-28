use std::{
    collections::BTreeMap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut map = BTreeMap::new();
    for _ in 0..n {
        let ext = input.next().unwrap().split('.').collect::<Vec<&str>>()[1];
        *map.entry(ext).or_insert(0) += 1;
    }
    let mut output = String::new();
    for (key, value) in &map {
        output.push_str(&format!("{key} {value}\n"));
    }
    print!("{output}");
}
