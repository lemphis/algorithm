use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let mut output = String::new();
    loop {
        let (n, mut k) = (f(), f());
        if n == 0 && k == 0 {
            break;
        }
        if n > k * 2 {
            k = n - k;
        }
        output.push_str(&format!(
            "{}\n",
            (k + 1..=n).fold(1, |acc, cur| acc * cur / (cur - k))
        ));
    }
    print!("{output}");
}