use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n = it.next().unwrap().parse::<usize>().unwrap();
    let mut s = Vec::with_capacity(n);
    for _ in 0..n {
        s.push(it.next().unwrap().parse::<i32>().unwrap());
    }
    s.reverse();
    let mut pi = pi(&s);
    pi.sort_by(|a, b| b.cmp(a));
    let &max = pi.first().unwrap();
    if max == 0 {
        print!("-1");
    } else {
        print!("{max} {}", pi.iter().filter(|&&x| x == max).count());
    }
}

fn pi(query: &Vec<i32>) -> Vec<usize> {
    let len = query.len();
    let mut pi = vec![0; len];
    let mut j = 0;
    for i in 1..len {
        while j > 0 && query[i] != query[j] {
            j = pi[j - 1];
        }
        if query[i] == query[j] {
            j += 1;
            pi[i] = j;
        }
    }
    pi
}