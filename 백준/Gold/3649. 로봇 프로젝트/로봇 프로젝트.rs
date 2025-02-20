use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next();
    let mut output = String::with_capacity(1024);
    while let Some(x) = f() {
        let x = x * 10_000_000;
        let n = f().unwrap();
        let mut lens = Vec::with_capacity(n);
        for _ in 0..n {
            let len = f().unwrap();
            if len < x {
                lens.push(len);
            }
        }
        lens.sort_unstable();
        let mut ans_len = 0;
        for i in 0..lens.len().saturating_sub(1) {
            let search = lens[i + 1..].binary_search(&(x - lens[i]));
            if search.is_ok() {
                ans_len = lens[i];
                break;
            }
        }
        if ans_len > 0 {
            output.push_str(&format!("yes {ans_len} {}\n", x - ans_len));
        } else {
            output.push_str("danger\n");
        }
    }

    print!("{output}");
}