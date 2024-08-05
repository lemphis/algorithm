use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let (n, m) = (it.next().unwrap(), it.next().unwrap());
    let mut pq = BinaryHeap::new();
    for _ in 0..n {
        pq.push(Reverse(it.next().unwrap()));
    }
    for _ in 0..m {
        let Reverse(a) = pq.pop().unwrap();
        let Reverse(b) = pq.pop().unwrap();
        pq.push(Reverse(a + b));
        pq.push(Reverse(a + b));
    }
    print!("{}", pq.iter().map(|Reverse(x)| x).sum::<usize>());
}