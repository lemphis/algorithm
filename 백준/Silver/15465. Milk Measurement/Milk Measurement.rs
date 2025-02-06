use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let n: usize = f().parse().unwrap();
    let mut list: Vec<(i32, &str, i32)> = (0..n)
        .map(|_| (f().parse().unwrap(), f(), f().parse().unwrap()))
        .collect();
    list.sort();

    let mut cows = [("Bessie", 7), ("Elsie", 7), ("Mildred", 7)];
    let mut rank = Vec::from_iter(cows.iter().map(|cow| cow.0));
    let mut count = 0;
    for (_, name, d) in list {
        let idx = cows.iter().position(|cow| cow.0 == name).unwrap();
        cows[idx].1 += d;
        cows.sort_by(|a, b| b.1.cmp(&a.1));
        let temp: Vec<&str> = cows
            .iter()
            .filter(|&cow| cows[0].1 == cow.1)
            .map(|&cow| cow.0)
            .collect();
        if rank != temp {
            rank = temp;
            count += 1;
        }
    }
    print!("{count}");
}