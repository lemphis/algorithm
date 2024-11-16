use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for _ in 0..t {
        let mut n = f();
        let mut count = 0;
        while n > 0 {
            count += n / 5;
            n /= 5;
        }
        output.push_str(&format!("{}\n", count));
    }
    print!("{output}");
}