use std::{
    collections::BinaryHeap,
    fmt::Write,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = it.next().unwrap();
    let mut pq = BinaryHeap::new();
    let mut output = String::new();
    for _ in 0..n {
        let cnt = it.next().unwrap();
        if cnt == 0 {
            if let Some(x) = pq.pop() {
                writeln!(output, "{x}").unwrap();
            } else {
                writeln!(output, "-1").unwrap();
            }
        } else {
            for _ in 0..cnt {
                pq.push(it.next().unwrap());
            }
        }
    }
    print!("{output}");
}