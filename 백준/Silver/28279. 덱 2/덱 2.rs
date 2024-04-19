use std::{
    collections::VecDeque,
    io::{stdin, Read},
};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap();
    let mut deque = VecDeque::new();
    let mut output = String::new();
    for _ in 0..n {
        let command = input.next().unwrap();
        match command {
            1 => deque.push_front(input.next().unwrap()),
            2 => deque.push_back(input.next().unwrap()),
            3 => output.push_str(&format!("{}{}", if deque.is_empty() {-1} else {deque.pop_front().unwrap()}, "\n")),
            4 => output.push_str(&format!("{}{}", if deque.is_empty() {-1} else {deque.pop_back().unwrap()}, "\n")),
            5 => output.push_str(&format!("{}{}", deque.len(), "\n")),
            6 => output.push_str(&format!("{}{}", if deque.is_empty() {1} else {0}, "\n")),
            7 => output.push_str(&format!("{}{}", if deque.is_empty() {-1} else {*deque.front().unwrap()}, "\n")),
            8 => output.push_str(&format!("{}{}", if deque.is_empty() {-1} else {*deque.back().unwrap()}, "\n")),
            _ => unreachable!(),
        }
    }
    print!("{}", output);
}