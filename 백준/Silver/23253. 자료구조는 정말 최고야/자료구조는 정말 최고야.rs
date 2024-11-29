use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (_, m) = (f(), f());
    let mut dummies = vec![Vec::new(); m];
    for dummy in dummies.iter_mut() {
        let k = f();
        for _ in 0..k {
            let num = f() - 1;
            if !dummy.is_empty() && *dummy.last().unwrap() < num {
                print!("No");
                return;
            }
            dummy.push(num);
        }
    }
    print!("Yes");
}