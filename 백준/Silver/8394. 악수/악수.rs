use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    print!(
        "{}",
        match n {
            1 => 1,
            2 => 2,
            3.. => {
                let (mut a, mut b) = (1, 2);
                for _ in 3..=n {
                    let sum = (a + b) % 10;
                    a = b;
                    b = sum;
                }
                b
            }
            _ => unreachable!(),
        }
    );
}