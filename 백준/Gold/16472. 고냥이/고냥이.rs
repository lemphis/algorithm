use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, s) = (
        f().parse::<usize>().unwrap(),
        f().chars().collect::<Vec<_>>(),
    );
    let (mut l, mut max_len) = (0, 0);
    let (mut alp_count, mut dupe_count) = ([0; 26], 0);
    for r in 0..s.len() {
        let r_idx = (s[r] as u8 - b'a') as usize;
        if alp_count[r_idx] == 0 {
            dupe_count += 1;
        }
        alp_count[r_idx] += 1;
        while dupe_count > n {
            let l_idx = (s[l] as u8 - b'a') as usize;
            alp_count[l_idx] -= 1;
            if alp_count[l_idx] == 0 {
                dupe_count -= 1;
            }
            l += 1;
        }
        max_len = max_len.max(r - l + 1);
    }

    print!("{max_len}");
}