use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut picture = vec![vec![0; 100]; 100];
    for _ in 0..n {
        let (x1, y1, x2, y2) = (f() - 1, f() - 1, f() - 1, f() - 1);
        for r in y1..=y2 {
            for c in x1..=x2 {
                picture[r][c] += 1;
            }
        }
    }
    let mut ans = 0;
    for r in picture.iter() {
        for &count in r.iter() {
            if count > m {
                ans += 1;
            }
        }
    }
    print!("{ans}");
}