use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for _ in 0..t {
        let n = f();
        let mut votes = (0..n).map(|i| (f(), i + 1)).collect::<Vec<_>>();
        votes.sort_unstable();
        let sum = votes.iter().map(|(vote, _)| vote).sum::<usize>();
        let max = votes.iter().max().unwrap().0;
        if votes[n - 1].0 == votes[n - 2].0 {
            output.push_str("no winner\n");
        } else {
            output.push_str(&format!(
                "{} winner {}\n",
                if sum / 2 < max {
                    "majority"
                } else {
                    "minority"
                },
                votes[n - 1].1
            ));
        }
    }

    print!("{output}");
}