use std::{
    collections::BinaryHeap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dasom = input.next().unwrap();
    let mut pq = BinaryHeap::with_capacity(n - 1);
    for _ in 0..n - 1 {
        pq.push(input.next().unwrap());
    }
    let mut cnt = 0;
    while pq.len() > 0 && dasom <= *pq.peek().unwrap() {
        let top = pq.pop().unwrap();
        pq.push(top - 1);
        dasom += 1;
        cnt += 1;
    }
    print!("{}", cnt);
}