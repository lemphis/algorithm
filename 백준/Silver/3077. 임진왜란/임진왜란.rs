use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();
    let answer: HashMap<&str, usize> =
        HashMap::from_iter((0..n).map(|i| (f(), i)).collect::<Vec<_>>());
    let hyeonwoo_answer: Vec<&str> = (0..n).map(|_| f()).collect();
    let mut count = 0;
    for i in 0..n - 1 {
        for j in i + 1..n {
            if answer[hyeonwoo_answer[i]] < answer[hyeonwoo_answer[j]] {
                count += 1;
            }
        }
    }
    print!("{}/{}", count, n * (n - 1) / 2);
}