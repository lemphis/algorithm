use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut players = (0..n)
        .map(|_| {
            (
                input.next().unwrap(),
                input.next().unwrap(),
                input.next().unwrap(),
            )
        })
        .collect::<Vec<_>>();
    players.sort_by(|&a, &b| b.2.cmp(&a.2));
    let mut output = String::new();
    players
        .iter()
        .take(2)
        .for_each(|&(country, player, _)| output.push_str(&format!("{} {}\n", country, player)));
    if players[0].0 == players[1].0 {
        for &(country, player, _) in players.iter().skip(2) {
            if country != players[0].0 {
                output.push_str(&format!("{} {}", country, player));
                break;
            }
        }
    } else {
        output.push_str(&format!("{} {}", players[2].0, players[2].1))
    }
    print!("{output}");
}