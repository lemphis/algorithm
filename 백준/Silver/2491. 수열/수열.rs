use std::{cmp::Ordering, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let (mut before, mut inc_count, mut dec_count, mut max) = (input.next().unwrap(), 1, 1, 1);
    for _ in 1..n {
        let num = input.next().unwrap();
        match num.cmp(&before) {
            Ordering::Less => {
                dec_count += 1;
                inc_count = 1;
            }
            Ordering::Greater => {
                inc_count += 1;
                dec_count = 1;
            }
            Ordering::Equal => {
                inc_count += 1;
                dec_count += 1;
            }
        }
        if max < inc_count {
            max = inc_count;
        }
        if max < dec_count {
            max = dec_count;
        }
        before = num;
    }
    print!("{max}");
}