use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, _) = (f(), f());
    let colors: Vec<_> = (0..n).map(|_| f()).collect();

    let (mut l, mut count) = (0, 1);
    for (i, color) in colors.iter().enumerate().skip(1) {
        if *color == colors[i - 1] {
            count = count.max(i - l);
            l = i;
        }
    }

    print!("{}", count.max(n - l));
}