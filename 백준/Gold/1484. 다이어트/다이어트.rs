use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let g = f();

    let (mut l, mut r): (usize, usize) = (1, 2);
    let mut nums = Vec::new();
    while r < 500_001 {
        match r.pow(2) - l.pow(2) {
            n if n > g => l += 1,
            n if n < g => r += 1,
            n if n == g => {
                nums.push(r);
                r += 1;
                l += 1;
            }
            _ => unreachable!(),
        }
    }
    print!(
        "{}",
        if nums.is_empty() {
            String::from("-1")
        } else {
            nums.iter()
                .map(usize::to_string)
                .collect::<Vec<_>>()
                .join("\n")
        }
    );
}