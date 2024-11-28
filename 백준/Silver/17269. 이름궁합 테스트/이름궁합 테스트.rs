use std::io::{self, stdin};

const STROKES: [i32; 26] = [
    3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1,
];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (n, m, a, b) = (
        f().parse::<usize>().unwrap(),
        f().parse::<usize>().unwrap(),
        f(),
        f(),
    );
    let min = n.min(m);
    let (a_chars, b_chars) = (a.chars().collect::<Vec<_>>(), b.chars().collect::<Vec<_>>());
    let mut zip = String::new();
    for i in 0..min {
        zip.push_str(&format!("{}{}", a_chars[i], b_chars[i]));
    }
    for &c in a_chars.iter().skip(min) {
        zip.push(c);
    }
    for &c in b_chars.iter().skip(min) {
        zip.push(c);
    }

    let mut counts = zip
        .chars()
        .map(|c| STROKES[usize::from(c as u8 - b'A')])
        .collect::<Vec<_>>();
    while counts.len() > 2 {
        counts = counts
            .windows(2)
            .map(|w| (w[0] + w[1]) % 10)
            .collect::<Vec<_>>();
    }
    print!(
        "{}%",
        counts
            .iter()
            .map(|count| count.to_string())
            .collect::<String>()
            .parse::<usize>()
            .unwrap()
    );
}