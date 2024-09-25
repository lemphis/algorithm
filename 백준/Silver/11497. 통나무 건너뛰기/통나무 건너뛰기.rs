use std::{
    collections::VecDeque,
    fmt::Write,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let n = input.next().unwrap();
        let mut arr = input.by_ref().take(n).collect::<Vec<_>>();
        arr.sort_unstable();
        let mut logs = VecDeque::with_capacity(n);
        for (i, &log) in arr.iter().enumerate() {
            if i & 1 == 0 {
                logs.push_front(log);
            } else {
                logs.push_back(log);
            }
        }
        let mut max_diff = 0;
        for i in 0..n - 1 {
            max_diff = max_diff.max(logs[i + 1].abs_diff(logs[i]));
        }
        writeln!(output, "{max_diff}").unwrap();
    }
    print!("{output}");
}