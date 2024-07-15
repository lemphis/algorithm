use std::{
    collections::HashSet,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut it = input.split_ascii_whitespace();
    loop {
        let s = it.next().unwrap();
        if s == "*" {
            break;
        }
        let mut is_surprise = true;
        let s_chars = s.chars().collect::<Vec<_>>();
        for interval in 1..s.len() {
            let size = s.len() - interval;
            let mut set = HashSet::new();
            for i in 0..s.len() - 1 {
                let mut l = i;
                let mut r = l + interval;
                while r < s.len() {
                    set.insert(format!("{}{}", s_chars[l], s_chars[r]));
                    l += interval;
                    r += interval;
                }
            }
            if size != set.len() {
                is_surprise = false;
                break;
            }
        }
        println!(
            "{s} is {}surprising.",
            if is_surprise { "" } else { "NOT " }
        );
    }
}