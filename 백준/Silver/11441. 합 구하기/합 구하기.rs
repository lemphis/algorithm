use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let mut sums = vec![0; n + 1];
    sums[0] = 0;
    for i in 1..=n {
        sums[i] = sums[i - 1] + f();
    }
    let m = f() as usize;
    let mut output = String::new();
    for _ in 0..m {
        let (i, j) = (f() as usize, f() as usize);
        output.push_str(&format!("{}\n", sums[j] - sums[i - 1]));
    }
    print!("{output}");
}