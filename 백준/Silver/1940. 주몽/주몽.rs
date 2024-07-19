use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let (n, m) = (it.next().unwrap(), it.next().unwrap());
    let mut ids = vec![0usize; n];
    for id in ids.iter_mut() {
        *id = it.next().unwrap();
    }
    ids.sort();
    let mut l = 0;
    let mut r = n - 1;
    let mut ans = 0;
    while l < r {
        if ids[l] + ids[r] < m {
            l += 1;
        } else if ids[l] + ids[r] > m {
            r -= 1;
        } else {
            l += 1;
            ans += 1;
        }
    }
    print!("{}", ans);
}