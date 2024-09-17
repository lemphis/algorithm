use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    if n < 4 {
        print!("0");
        return;
    }
    print!("{}", (1..5).fold(1, |acc, cur| acc * (n - cur + 1) / cur));
}