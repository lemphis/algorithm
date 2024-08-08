use std::{
    array,
    collections::BinaryHeap,
    io::{self, Read},
};

const PLAYERS_COUNT: usize = 11;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (n, k) = (it.next().unwrap(), it.next().unwrap());
    let mut queues: [BinaryHeap<usize>; PLAYERS_COUNT] = array::from_fn(|_| BinaryHeap::new());
    for _ in 0..n {
        let (p, w) = (it.next().unwrap(), it.next().unwrap());
        queues[p - 1].push(w);
    }
    for _ in 0..k {
        for queue in queues.iter_mut() {
            if !queue.is_empty() {
                let top = queue.pop().unwrap();
                queue.push(top - 1);
            }
        }
    }
    print!(
        "{}",
        queues
            .iter()
            .map(|queue| if queue.is_empty() {
                0
            } else {
                *queue.peek().unwrap()
            })
            .sum::<usize>()
    );
}