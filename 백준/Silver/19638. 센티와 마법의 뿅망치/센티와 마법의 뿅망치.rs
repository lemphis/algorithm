use std::{
    collections::BinaryHeap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<i32>);
    let (n, h, t) = (it.next().unwrap(), it.next().unwrap(), it.next().unwrap());
    let mut pq = BinaryHeap::new();
    for _ in 0..n {
        pq.push(it.next().unwrap());
    }

    if *pq.peek().unwrap() < h {
        println!("YES");
        println!("0");
        return;
    }
    for i in 0..t {
        let top = pq.pop().unwrap();
        if top == 1 {
            pq.push(top);
            break;
        }
        pq.push(top / 2);
        if *pq.peek().unwrap() < h {
            println!("YES");
            println!("{}", i + 1);
            return;
        }
    }
    println!("NO");
    println!("{}", pq.pop().unwrap());
}