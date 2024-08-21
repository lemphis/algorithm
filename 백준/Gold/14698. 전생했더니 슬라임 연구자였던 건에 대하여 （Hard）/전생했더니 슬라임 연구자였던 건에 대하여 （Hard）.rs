use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    fmt::Write,
    io::{self, Read},
};

const DIVISOR: u128 = 1_000_000_007;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace().flat_map(str::parse::<u128>);
    let t = it.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let n = it.next().unwrap();
        let mut sum = 1;
        let mut min_heap: BinaryHeap<Reverse<u128>> =
            (0..n).map(|_| Reverse(it.next().unwrap())).collect();
        while min_heap.len() > 1 {
            let Reverse(first) = min_heap.pop().unwrap();
            let Reverse(second) = min_heap.pop().unwrap();
            let new_slime = first * second;
            min_heap.push(Reverse(new_slime));
            sum = new_slime * sum % DIVISOR;
        }
        writeln!(output, "{}", sum).unwrap();
    }
    print!("{output}");
}