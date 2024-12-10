use std::io::{self, stdin};

const MAX: usize = 4_000_001;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (a, b, d) = (f(), f(), f());
    let mut is_prime = [true; MAX];
    for i in 2..(MAX as f64).sqrt() as usize + 1 {
        if is_prime[i] {
            for m in (i * i..MAX).step_by(i) {
                is_prime[m] = false;
            }
        }
    }
    let mut count = 0;
    for i in a..=b {
        if is_prime[i]
            && i.to_string()
                .contains(char::from_digit(d as u32, 10).unwrap())
        {
            count += 1;
        }
    }
    print!("{count}");
}