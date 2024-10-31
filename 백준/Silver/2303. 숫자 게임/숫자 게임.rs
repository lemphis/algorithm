use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let (mut max, mut idx) = (0, 0);
    for num in 0..n {
        let cards = (0..5).map(|_| f()).collect::<Vec<_>>();
        for i in 0..3 {
            for j in i + 1..4 {
                for k in j + 1..5 {
                    let r = (cards[i] + cards[j] + cards[k]) % 10;
                    if max <= r {
                        max = r;
                        idx = num + 1;
                    }
                }
            }
        }
    }
    print!("{idx}");
}