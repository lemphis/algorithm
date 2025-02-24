use std::{
    collections::HashSet,
    io::{self, BufReader, Read},
};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next();
    let mut output = String::with_capacity(1024);
    while let Some(n) = f() {
        let n = n as usize;
        let nums: Vec<_> = (0..n).map(|_| f().unwrap()).collect();
        let mut s: HashSet<i32> = HashSet::from_iter((1..n as i32).into_iter());
        let mut pass = true;
        for i in 0..n - 1 {
            if !s.remove(&(nums[i + 1] - nums[i]).abs()) {
                pass = false;
                break;
            }
        }
        if !pass || s.len() > 0 {
            output.push_str("Not jolly\n");
        } else {
            output.push_str("Jolly\n");
        }
    }
    print!("{output}");
}