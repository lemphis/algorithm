use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let mut map = vec![vec![false; 100]; 100];
    for _ in 0..4 {
        let (x1, y1, x2, y2) = (f() - 1, f() - 1, f() - 1, f() - 1);
        for r in y1..y2 {
            for c in x1..x2 {
                map[r][c] = true;
            }
        }
    }
    print!(
        "{}",
        map.iter()
            .map(|r| r.iter().filter(|&&c| c).count())
            .sum::<usize>()
    );
}