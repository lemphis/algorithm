use std::{
    collections::BinaryHeap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (n, m) = (it.next().unwrap(), it.next().unwrap());
    let mut pq = BinaryHeap::new();
    for _ in 0..n {
        pq.push(it.next().unwrap());
    }
    for _ in 0..m {
        let num = it.next().unwrap();
        if let Some(top) = pq.pop() {
            if top >= num {
                if top - num > 0 {
                    pq.push(top - num);
                }
            } else {
                print!("0");
                return;
            }
        } else {
            print!("0");
            return;
        }
    }
    print!("1");
}