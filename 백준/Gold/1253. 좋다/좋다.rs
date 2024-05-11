use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap() as usize;
    if n < 3 {
        print!("{}", 0);
        return;
    }
    let mut v = vec![0; n];
    for i in 0..n {
        v[i] = input.next().unwrap();
    }
    v.sort();
    let mut good_cnt = 0;
    for i in 0..n {
        let mut lo = 0;
        let mut hi = n - 1;
        while lo < hi {
            let mid = v[lo] + v[hi];
            if mid < v[i] {
                lo += 1;
            } else if mid > v[i] {
                hi -= 1;
            } else {
                if lo != i && hi != i {
                    good_cnt += 1;
                    break;
                } else if lo == i {
                    lo += 1;
                } else if hi == i {
                    hi -= 1;
                }
            }
        }
    }
    print!("{}", good_cnt);
}