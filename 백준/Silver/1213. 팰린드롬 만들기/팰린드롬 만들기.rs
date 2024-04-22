use std::{
    collections::BTreeMap,
    io::{stdin, Read},
};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let input = input.split_ascii_whitespace().collect::<String>();
    let mut map = BTreeMap::new();
    for char in input.chars() {
        *map.entry(char).or_insert(0) += 1;
    }
    let mut odd_char = '?';
    let mut str = vec!['!'; input.len()];
    let mut idx = 0;
    for (char, count) in &map {
        if count & 1 == 1 {
            if odd_char != '?' {
                print!("I'm Sorry Hansoo");
                return;
            }
            odd_char = *char;
            str[input.len() / 2] = *char;
        }
        for _ in 0..(*count / 2) {
            str[idx] = *char;
            str[(input.len() - 1) - idx] = *char;
            idx += 1;
        }
    }
    print!("{}", str.into_iter().collect::<String>());
}
