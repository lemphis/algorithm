use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let n = it.next().unwrap();
    let mut classes = vec![(0, 0); n];
    for class in classes.iter_mut() {
        let _ = it.next().unwrap();
        *class = (it.next().unwrap(), it.next().unwrap());
    }
    classes.sort();
    let mut heap: BinaryHeap<Reverse<usize>> = BinaryHeap::new();
    heap.push(Reverse(classes[0].1));
    for (s, t) in classes.iter().skip(1) {
        let Reverse(value) = *heap.peek().unwrap();
        if value <= *s {
            heap.pop();
        }
        heap.push(Reverse(*t));
    }
    print!("{}", heap.len());
}