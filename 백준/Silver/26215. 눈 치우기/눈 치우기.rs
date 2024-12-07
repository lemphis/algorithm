use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut snows = (0..n).map(|_| f()).collect::<Vec<_>>();
    for i in 0..1440 {
        snows = snows
            .iter()
            .filter(|&&snow| snow > 0)
            .cloned()
            .collect::<Vec<_>>();
        snows.sort_by(|a, b| b.cmp(a));
        if snows.is_empty() {
            print!("{i}");
            return;
        }
        if *snows.last().unwrap() == 0 {
            snows.pop();
            if snows.len() > 1 && *snows.last().unwrap() == 0 {
                snows.pop();
            }
        }
        let len = snows.len();
        snows[0] -= 1;
        if len > 1 {
            snows[1] -= 1;
        }
    }
    print!(
        "{}",
        if snows.is_empty() || snows.iter().all(|&snow| snow == 0) {
            "1440"
        } else {
            "-1"
        }
    );
}