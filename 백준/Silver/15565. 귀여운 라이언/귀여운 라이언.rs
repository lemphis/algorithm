use std::{
    io::{self, stdin},
    usize,
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let is_ryan: Vec<bool> = (0..n).map(|_| f() == 1).collect();

    let mut ans = usize::MAX;
    let (mut l, mut r, mut ryan_count) = (0, 0, 0);
    while r < n {
        if is_ryan[r] {
            ryan_count += 1;
        }
        while ryan_count >= k && l < r {
            if ryan_count == k {
                ans = ans.min(r - l + 1);
            }
            if is_ryan[l] {
                ryan_count -= 1;
            }
            l += 1;
        }
        r += 1;
    }
    print!("{}", if ans == usize::MAX { -1 } else { ans as i32 });
}