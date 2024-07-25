use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace();
    let (n, _, s) = (
        it.next().unwrap().parse::<usize>().unwrap(),
        it.next().unwrap(),
        it.next().unwrap(),
    );
    let mut compare_str = String::with_capacity(n);
    for i in 0..(n * 2 + 1) {
        compare_str.push(if i & 1 == 0 { 'I' } else { 'O' });
    }
    let s_chars: Vec<char> = s.chars().collect();
    let compare_str_chars: Vec<char> = compare_str.chars().collect();
    let mut ans = 0;
    for i in 0..(s.len() - compare_str_chars.len() + 1) {
        let mut is_same = true;
        for j in 0..(n * 2 + 1) {
            if s_chars[i + j] != compare_str_chars[j] {
                is_same = false;
                break;
            }
        }
        if is_same {
            ans += 1;
        }
    }

    print!("{ans}");
}