use std::{
    cmp::{Ordering, Reverse},
    collections::BinaryHeap,
    io::{self, stdin},
};

#[derive(Eq, PartialEq)]
struct Beer {
    preference: i64,
    abv: i64,
}

impl Ord for Beer {
    fn cmp(&self, other: &Self) -> Ordering {
        match self.abv.cmp(&other.abv) {
            Ordering::Equal => {}
            ord => return ord,
        }
        other.preference.cmp(&self.preference)
    }
}

impl PartialOrd for Beer {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let (n, m, k) = (
        input.next().unwrap() as usize,
        input.next().unwrap(),
        input.next().unwrap() as usize,
    );
    let mut beers = Vec::with_capacity(k);
    for _ in 0..k {
        let beer = Beer {
            preference: input.next().unwrap(),
            abv: input.next().unwrap(),
        };
        beers.push(beer);
    }
    beers.sort_unstable();
    let mut pq = BinaryHeap::with_capacity(n);
    let mut level = i64::MAX;
    let mut sum = 0;
    for beer in beers.iter() {
        pq.push(Reverse(beer.preference));
        sum += beer.preference;
        if pq.len() == n {
            if sum >= m {
                level = level.min(beer.abv);
            }
            let top = pq.pop().unwrap();
            sum -= top.0;
        }
    }
    print!("{}", if level == i64::MAX { -1 } else { level });
}