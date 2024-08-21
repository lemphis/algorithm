use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    fmt::Write,
    io::{self, stdin},
};

const DIVISOR: u64 = 1_000_000_007;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<u64>);
    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let n = input.next().unwrap();
        let mut sum = 1;
        let mut min_heap: BinaryHeap<_> = (0..n).map(|_| Reverse(input.next().unwrap())).collect();
        while min_heap.len() > 1 {
            let Reverse(first) = min_heap.pop().unwrap();
            let Reverse(second) = min_heap.pop().unwrap();
            let new_slime = first * second;
            min_heap.push(Reverse(new_slime));
            sum = ((new_slime % DIVISOR) * sum) % DIVISOR;
        }
        writeln!(output, "{}", sum).unwrap();
    }
    print!("{output}");
}