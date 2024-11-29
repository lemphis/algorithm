use std::{
    io::{self, stdin},
    usize,
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (_, m) = (f(), f());
    for _ in 0..m {
        let k = f();
        let mut last = usize::MAX;
        for _ in 0..k {
            let num = f() - 1;
            if last < num {
                print!("No");
                return;
            }
            last = num;
        }
    }
    print!("Yes");
}