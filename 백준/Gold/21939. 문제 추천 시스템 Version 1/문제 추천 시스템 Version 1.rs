use std::{
    cmp::Reverse,
    collections::{BinaryHeap, HashMap},
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace();
    let n = it.next().unwrap().parse::<usize>().unwrap();
    let mut map = HashMap::new();
    for _ in 0..n {
        let (problem_num, difficulty) = (
            it.next().unwrap().parse::<i32>().unwrap(),
            it.next().unwrap().parse::<i32>().unwrap(),
        );
        map.insert(problem_num, difficulty);
    }
    let mut max_heap = BinaryHeap::new();
    let mut min_heap = BinaryHeap::new();
    for (&problem_num, &difficulty) in map.iter() {
        max_heap.push((difficulty, problem_num));
        min_heap.push(Reverse((difficulty, problem_num)));
    }
    let m = it.next().unwrap().parse::<usize>().unwrap();
    let mut output = String::new();
    for _ in 0..m {
        let command = it.next().unwrap();
        match command {
            "recommend" => {
                let x = it.next().unwrap().parse::<i32>().unwrap();
                let problem_num = if x == 1 {
                    loop {
                        let next = max_heap.peek().unwrap();
                        if map.contains_key(&next.1) {
                            if *map.get(&next.1).unwrap() != next.0 {
                                let mut next = max_heap.pop().unwrap();
                                next.0 = *map.get(&next.1).unwrap();
                                max_heap.push(next);
                            } else {
                                break next.1;
                            }
                        } else {
                            max_heap.pop();
                        }
                    }
                } else {
                    loop {
                        let Reverse(next) = min_heap.peek().unwrap();
                        if map.contains_key(&next.1) {
                            if *map.get(&next.1).unwrap() != next.0 {
                                let Reverse(mut next) = min_heap.pop().unwrap();
                                next.0 = *map.get(&next.1).unwrap();
                                min_heap.push(Reverse(next));
                            } else {
                                break next.1;
                            }
                        } else {
                            min_heap.pop();
                        }
                    }
                };
                output.push_str(&format!("{}\n", problem_num));
            }
            "add" => {
                let (problem_num, difficulty) = (
                    it.next().unwrap().parse::<i32>().unwrap(),
                    it.next().unwrap().parse::<i32>().unwrap(),
                );
                max_heap.push((difficulty, problem_num));
                min_heap.push(Reverse((difficulty, problem_num)));
                map.insert(problem_num, difficulty);
            }
            "solved" => {
                let problem_num = it.next().unwrap().parse::<i32>().unwrap();
                map.remove(&problem_num);
            }
            _ => unreachable!(),
        }
    }
    print!("{output}");
}