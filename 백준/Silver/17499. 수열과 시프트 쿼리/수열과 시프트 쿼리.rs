use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let (n, q) = (f() as usize, f());
    let mut nums: Vec<i32> = (0..n).map(|_| f()).collect();
    let mut ptr_idx = 0;
    for _ in 0..q {
        match f() {
            1 => {
                let (idx, num) = (f() as usize - 1, f());
                nums[(idx + ptr_idx) % n] += num;
            }
            2 => ptr_idx = (ptr_idx + n - f() as usize) % n,
            3 => ptr_idx = (ptr_idx + f() as usize) % n,
            _ => unreachable!(),
        }
    }
    print!(
        "{}",
        nums.iter()
            .cycle()
            .skip(ptr_idx)
            .take(n)
            .map(ToString::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}