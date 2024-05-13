use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let input = input.split_ascii_whitespace().next().unwrap();
    let mut v = input.as_bytes().iter().enumerate().collect::<Vec<_>>();
    let mut first_idx = usize::MAX;
    for i in 0..v.len() {
        if *v[i].1 as char == 'X' {
            if first_idx == usize::MAX {
                first_idx = i;
            }
        } else if first_idx != usize::MAX {
            let len = i - first_idx;
            if len & 1 == 1 {
                print!("{}", -1);
                return;
            }
            if len % 4 == 0 {
                for item in v.iter_mut().take(i).skip(first_idx) {
                    item.1 = &b'A';
                }
            } else {
                let q = len / 4;
                for item in v.iter_mut().skip(first_idx).take(q * 4) {
                    item.1 = &b'A';
                }
                for item in v.iter_mut().take(i).skip(first_idx + q * 4) {
                    item.1 = &b'B';
                }
            }
            first_idx = usize::MAX;
        }
    }
    if first_idx != usize::MAX {
        let len = v.len() - first_idx;
        if len & 1 == 1 {
            print!("{}", -1);
            return;
        }
        if len % 4 == 0 {
            for item in v.iter_mut().skip(first_idx) {
                item.1 = &b'A';
            }
        } else {
            let q = len / 4;
            for item in v.iter_mut().skip(first_idx).take(q * 4) {
                item.1 = &b'A';
            }
            for item in v.iter_mut().skip(first_idx + q * 4) {
                item.1 = &b'B';
            }
        }
    }
    print!("{}", v.iter().map(|(_, &c)| c as char).collect::<String>());
}