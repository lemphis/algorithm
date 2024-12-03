use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut n = input.next().unwrap();
    let mut sum = 0;
    let mut count = 0;
    while n > 0 {
        if n & 1 == 1 {
            sum += 3usize.pow(count);
        }
        count += 1;
        n >>= 1;
    }
    print!("{sum}");
}