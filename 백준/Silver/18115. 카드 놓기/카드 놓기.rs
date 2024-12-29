use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let commands = (0..n).map(|_| f()).collect::<Vec<_>>();
    let mut origin = VecDeque::with_capacity(n);
    for (idx, c) in commands.iter().rev().enumerate() {
        match c {
            1 => origin.push_front(idx + 1),
            2 => {
                let front = origin.pop_front().unwrap();
                origin.push_front(idx + 1);
                origin.push_front(front);
            }
            3 => origin.push_back(idx + 1),
            _ => unreachable!(),
        };
    }
    print!(
        "{}",
        origin
            .iter()
            .map(|num| num.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}