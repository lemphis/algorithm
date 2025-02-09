use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f();
    let size_count = [f(), f(), f(), f(), f(), f()];
    let (t, p) = (f(), f());

    let mut t_count = 0;
    for c in size_count {
        t_count += c / t;
        if c % t > 0 {
            t_count += 1;
        }
    }

    print!("{}\n{} {}", t_count, n / p, n % p);
}