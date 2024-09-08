use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let mut output = String::new();
    loop {
        let password = input.next().unwrap();
        if password == "end" {
            break;
        }
        let mut is_possible = true;
        let chars = password.chars().collect::<Vec<_>>();
        let mut consonant_pos = -1;
        let mut vowel_pos = -1;
        for (i, c) in chars.iter().enumerate() {
            if vowels.contains(c) {
                vowel_pos = i as i32;
            } else {
                consonant_pos = i as i32;
            }
            if (consonant_pos - vowel_pos).abs() == 3 {
                is_possible = false;
                break;
            }
        }
        if vowel_pos == -1 {
            is_possible = false;
        }
        if chars
            .windows(2)
            .any(|w| w[0] == w[1] && w[0] != 'e' && w[0] != 'o')
        {
            is_possible = false;
        }
        writeln!(
            output,
            "<{password}> is {}acceptable.",
            if is_possible { "" } else { "not " }
        )
        .unwrap();
    }
    print!("{output}");
}