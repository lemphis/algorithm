use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::with_capacity(1024);
    for _ in 0..t {
        let n = f();
        let nums: Vec<usize> = (0..n).map(|_| f() - 1).collect();
        let (mut visited, mut count) = (vec![false; n], 0);
        for start in 0..n {
            let mut i = start;
            if !visited[i] {
                while !visited[i] {
                    visited[i] = true;
                    i = nums[i];
                }
                count += 1;
            }
        }
        output.push_str(&format!("{count}\n"));
    }
    print!("{output}");
}