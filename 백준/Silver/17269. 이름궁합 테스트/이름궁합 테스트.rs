use std::{
    collections::HashMap,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, m, a, b) = (
        f().parse::<usize>().unwrap(),
        f().parse::<usize>().unwrap(),
        f(),
        f(),
    );
    let min = n.min(m);
    let (a_chars, b_chars) = (a.chars().collect::<Vec<_>>(), b.chars().collect::<Vec<_>>());
    let mut zip = String::new();
    for i in 0..min {
        zip.push_str(&format!("{}{}", a_chars[i], b_chars[i]));
    }
    for &c in a_chars.iter().skip(min) {
        zip.push(c);
    }
    for &c in b_chars.iter().skip(min) {
        zip.push(c);
    }

    let strokes = HashMap::from([
        ('A', 3),
        ('B', 2),
        ('C', 1),
        ('D', 2),
        ('E', 4),
        ('F', 3),
        ('G', 1),
        ('H', 3),
        ('I', 1),
        ('J', 1),
        ('K', 3),
        ('L', 1),
        ('M', 3),
        ('N', 2),
        ('O', 1),
        ('P', 2),
        ('Q', 2),
        ('R', 2),
        ('S', 1),
        ('T', 2),
        ('U', 1),
        ('V', 1),
        ('W', 1),
        ('X', 2),
        ('Y', 2),
        ('Z', 1),
    ]);
    let mut counts = zip.chars().map(|c| strokes[&c]).collect::<Vec<_>>();
    while counts.len() > 2 {
        counts = counts
            .iter()
            .enumerate()
            .skip(1)
            .map(|(i, &n)| (counts[i - 1] + n) % 10)
            .collect::<Vec<_>>();
    }
    let mut ans = counts[0].to_string();
    ans.push_str(&counts[1].to_string());
    print!("{}%", ans.parse::<i32>().unwrap());
}