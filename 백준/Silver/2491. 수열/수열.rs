use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let (mut before, mut inc_count, mut dec_count, mut max) = (input.next().unwrap(), 1, 1, 1);
    for _ in 1..n {
        let num = input.next().unwrap();
        inc_count = if num >= before { inc_count + 1 } else { 1 };
        dec_count = if num <= before { dec_count + 1 } else { 1 };
        max = max.max(inc_count).max(dec_count);
        before = num;
    }
    print!("{max}");
}