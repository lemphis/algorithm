use std::{
    cmp::Ordering,
    collections::BinaryHeap,
    io::{self, Read},
};

#[derive(PartialEq, Eq)]
struct Process {
    pid: i32,
    time: usize,
    priority: i32,
}

impl Ord for Process {
    fn cmp(&self, other: &Self) -> Ordering {
        self.priority
            .cmp(&other.priority)
            .then_with(|| other.pid.cmp(&self.pid))
    }
}

impl PartialOrd for Process {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (t, n) = (it.next().unwrap() as usize, it.next().unwrap() as usize);
    let mut scheduler = BinaryHeap::new();
    for _ in 0..n {
        scheduler.push(Process {
            pid: it.next().unwrap(),
            time: it.next().unwrap() as usize,
            priority: it.next().unwrap(),
        });
    }
    let mut output = String::with_capacity(2_000_000);
    for _ in 0..t {
        let mut process = scheduler.pop().unwrap();
        output.push_str(&format!("{}\n", process.pid));
        process.time -= 1;
        process.priority -= 1;
        if process.time > 0 {
            scheduler.push(process);
        }
    }
    print!("{output}");
}