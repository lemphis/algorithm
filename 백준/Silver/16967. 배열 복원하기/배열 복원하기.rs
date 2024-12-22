use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (h, w, x, y) = (f(), f(), f(), f());
    let mut arr = (0..h + x)
        .map(|_| (0..w + y).map(|_| f()).collect::<Vec<_>>())
        .collect::<Vec<_>>();
    for r in x..h + x {
        for c in y..w + y {
            arr[r][c] -= arr[r - x][c - y];
        }
    }
    let mut output = String::with_capacity(h * w * 2);
    for r in arr.iter().take(h) {
        for &num in r.iter().take(w) {
            output.push_str(&format!("{num} "));
        }
        output.push('\n');
    }
    print!("{output}");
}