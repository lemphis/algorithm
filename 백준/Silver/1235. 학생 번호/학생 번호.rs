use std::{
    collections::HashSet,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let arr = (0..n)
        .map(|_| input.next().unwrap().chars().rev().collect::<Vec<char>>())
        .collect::<Vec<_>>();
    let mut idx = arr[0].len();
    for i in 0..arr[0].len() {
        let mut set = HashSet::new();
        for v in arr.iter() {
            set.insert(v[0..i].to_vec().iter().collect::<String>());
        }
        if set.len() == n {
            idx = i;
            break;
        }
    }
    print!("{idx}");
}