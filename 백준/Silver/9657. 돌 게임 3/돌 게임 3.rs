use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut is_sk = [true; 1_001];
    is_sk[2] = false;
    for i in 7..=n {
        if is_sk[i - 1] && is_sk[i - 3] && is_sk[i - 4] {
            is_sk[i] = false;
        }
    }

    print!("{}", if is_sk[n] { "SK" } else { "CY" });
}