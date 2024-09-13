use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (_, m) = (input.next().unwrap(), input.next().unwrap());
    let mut max_pq = input.collect::<BinaryHeap<_>>();
    let mut min_pq = BinaryHeap::new();
    for _ in 0..m {
        min_pq.push(Reverse(0));
    }
    while !max_pq.is_empty() {
        let mut top = min_pq.pop().unwrap();
        top.0 += max_pq.pop().unwrap();
        min_pq.push(top);
    }
    for _ in 0..m - 1 {
        min_pq.pop();
    }
    print!("{}", min_pq.peek().unwrap().0);
}