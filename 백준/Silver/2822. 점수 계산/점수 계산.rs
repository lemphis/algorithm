use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let mut scores: Vec<(usize, usize)> = (1..=8).map(|i| (it.next().unwrap(), i)).collect();
    scores.sort();
    scores.reverse();
    let sum: usize = scores.iter().take(5).map(|(score, _)| score).sum();
    println!("{}", sum);
    let mut indexes: Vec<usize> = scores.iter().map(|(_, i)| *i).take(5).collect();
    indexes.sort();
    for i in indexes.iter() {
        print!("{} ", i);
    }
}