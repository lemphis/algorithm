use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let words = input.next().unwrap().split('*').collect::<Vec<&str>>();
    let mut output = String::new();
    let mut idx;
    for _ in 0..n {
        let str = input.next().unwrap();
        if str.find(words[0]) == None || str.find(words[0]).unwrap() != 0 {
            output.push_str("NE\n");
            continue;
        };
        idx = words[0].len();
        for i in 1..words.len() - 1 {
            match str[idx..].find(words[i]) {
                Some(find_idx) => idx = find_idx + words[i].len(),
                None => idx = 0,
            }
        }
        if idx == 0 {
            output.push_str("NE\n");
            continue;
        }
        let last_word = words[words.len() - 1];
        if str.len() - idx < last_word.len() || str[str.len() - last_word.len()..] != *last_word {
            output.push_str("NE\n");
            continue;
        };
        output.push_str("DA\n");
    }
    print!("{output}");
}
