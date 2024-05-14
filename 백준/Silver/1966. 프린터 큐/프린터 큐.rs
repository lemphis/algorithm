use std::{
    cmp::Ordering,
    collections::{BinaryHeap, VecDeque},
    io::{self, Read},
};

#[derive(Eq, PartialEq, Clone)]
struct PrintOrder {
    priority: usize,
    index: usize,
}

impl Ord for PrintOrder {
    fn cmp(&self, other: &Self) -> Ordering {
        match self.priority.cmp(&other.priority) {
            Ordering::Equal => self.index.cmp(&other.index).reverse(),
            non_eq => non_eq,
        }
    }
}

impl PartialOrd for PrintOrder {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let tc = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..tc {
        let n = input.next().unwrap();
        let m = input.next().unwrap();
        let mut q = VecDeque::with_capacity(n);
        let mut pq = BinaryHeap::with_capacity(n);
        for i in 0..n {
            let print_order = PrintOrder {
                priority: input.next().unwrap(),
                index: i,
            };
            q.push_back(print_order.clone());
            pq.push(print_order);
        }
        let mut order = 1;
        while pq.len() > 0 {
            while pq.peek().unwrap().priority != q.front().unwrap().priority {
                let front = q.pop_front().unwrap();
                q.push_back(front);
            }
            if q.front().unwrap().index == m {
                break;
            }
            pq.pop();
            q.pop_front();
            order += 1;
        }
        output.push_str(&format!("{}\n", order));
    }
    print!("{output}");
}