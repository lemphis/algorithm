use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    for _ in 0..m {
        let k = f();
        let mut last = n;
        for _ in 0..k {
            let num = f();
            if last < num {
                print!("No");
                return;
            }
            last = num;
        }
    }
    print!("Yes");
}