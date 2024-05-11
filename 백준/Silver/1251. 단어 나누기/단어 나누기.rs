use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let input = input.split_ascii_whitespace().next().unwrap();
    let len = input.len();
    let mut sorted_str = String::new();
    for i in 1..len - 1 {
        for j in i + 1..len {
            let concatenated = [&input[..i], &input[i..j], &input[j..]]
                .map(|st| st.chars().rev().collect::<String>())
                .concat();
            if sorted_str.is_empty() {
                sorted_str = String::from(&concatenated);
            }
            sorted_str = sorted_str.min(concatenated);
        }
    }
    print!("{sorted_str}");
}