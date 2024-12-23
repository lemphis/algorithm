use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k, m) = (f(), f(), f());
    let (mut rev_count, mut is_rev) = (0, false);
    let mut nums = (1..=n).collect::<VecDeque<_>>();
    let mut output = String::with_capacity(n * 2);
    while !nums.is_empty() {
        if rev_count == m {
            rev_count = 0;
            is_rev = !is_rev;
        }
        if is_rev {
            for _ in 0..k {
                let pop = nums.pop_back().unwrap();
                nums.push_front(pop);
            }
            output.push_str(&format!("{}\n", nums.pop_front().unwrap()));
        } else {
            for _ in 0..k {
                let pop = nums.pop_front().unwrap();
                nums.push_back(pop);
            }
            output.push_str(&format!("{}\n", nums.pop_back().unwrap()));
        }
        rev_count += 1;
    }
    print!("{output}");
}