use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let lines = input.trim().lines().collect::<Vec<&str>>();
    let mut output = String::new();
    for c in 0..lines.iter().map(|x| x.len()).max().unwrap() {
        for r in 0..lines.len() {
            if let Some(ch) = lines[r].chars().nth(c) {
                output.push(ch);
            }
        }
    }
    print!("{output}");
}
