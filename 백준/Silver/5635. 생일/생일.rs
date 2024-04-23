use std::{
    collections::BTreeMap,
    io::{stdin, Read},
};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut map = BTreeMap::new();
    for _ in 0..n {
        let name = input.next().unwrap();
        let d = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();
        let y = input.next().unwrap().parse::<usize>().unwrap();
        let ymd = format!("{:04}{:02}{:02}", y, m, d);
        map.insert(ymd, name);
    }
    println!("{}", map.last_key_value().unwrap().1);
    println!("{}", map.first_key_value().unwrap().1);
}
