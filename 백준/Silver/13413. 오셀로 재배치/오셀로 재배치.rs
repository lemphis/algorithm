use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let t = f().parse::<usize>().unwrap();

    let mut output = String::new();
    for _ in 0..t {
        let _ = f();
        let (from, to) = (f(), f());

        let (mut b, mut w) = (0, 0);

        for (f, t) in from.chars().zip(to.chars()) {
            if f != t {
                if f == 'B' {
                    b += 1;
                } else {
                    w += 1;
                }
            }
        }
        output.push_str(&format!("{}\n", b.max(w)));
    }

    print!("{output}");
}