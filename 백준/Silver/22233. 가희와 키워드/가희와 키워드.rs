use std::{
    collections::HashSet,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, m) = (f().parse::<usize>().unwrap(), f().parse::<usize>().unwrap());
    let mut set = (0..n).map(|_| f()).collect::<HashSet<_>>();
    let mut output = String::new();
    for _ in 0..m {
        let keywords = f().split(",").collect::<Vec<_>>();
        for keyword in keywords.iter() {
            set.remove(keyword);
        }
        output.push_str(&format!("{}\n", set.len()));
    }
    print!("{output}");
}