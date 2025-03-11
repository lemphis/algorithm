use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(64);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let tc: usize = f().parse().unwrap();

    let mut output = String::with_capacity(1024);
    for _ in 0..tc {
        let letter = f().chars().collect::<Vec<char>>();
        let len = (letter.len() as f64).sqrt() as usize;
        let arr: Vec<Vec<char>> = letter
            .chunks(len)
            .map(|chunk: &[char]| chunk.to_vec())
            .collect();

        let mut origin = String::with_capacity(letter.len());
        for c in (0..len).rev() {
            for r in 0..len {
                origin.push(arr[r][c]);
            }
        }

        output.push_str(&format!("{origin}\n"));
    }

    print!("{output}");
}