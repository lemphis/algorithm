use std::{
    collections::BinaryHeap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let (n, m) = (input.next().unwrap() as usize, input.next().unwrap());
    let mut pq = BinaryHeap::new();
    let mut total_dissatisfaction = 0;
    let mut eggplant_count = 0;
    for _ in 0..n {
        let dissatisfaction = input.next().unwrap();
        total_dissatisfaction += dissatisfaction;
        pq.push(dissatisfaction);
        if total_dissatisfaction >= m {
            let top = pq.pop().unwrap();
            total_dissatisfaction -= top * 2;
            eggplant_count += 1;
        }
    }
    print!("{eggplant_count}");
}