use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut input = || input.next().unwrap();
    let n = input();
    let mut players = (0..n)
        .map(|_| (input(), input(), input()))
        .collect::<Vec<_>>();
    players.sort_by(|&a, &b| b.2.cmp(&a.2));
    let mut output = String::new();
    let mut count = vec![0; n + 1];
    let mut total_count = 0;
    for &(country, player, _) in players.iter() {
        if count[country] == 2 {
            continue;
        }
        output.push_str(&format!("{} {}\n", country, player));
        count[country] += 1;
        total_count += 1;
        if total_count == 3 {
            break;
        }
    }
    print!("{output}");
}