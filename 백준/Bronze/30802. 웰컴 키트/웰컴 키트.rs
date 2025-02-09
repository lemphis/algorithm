use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let size_count = [f(), f(), f(), f(), f(), f()];
    let (t, p) = (f(), f());
    print!(
        "{}\n{} {}",
        size_count.iter().map(|c| c.div_ceil(t)).sum::<usize>(),
        n / p,
        n % p
    );
}