use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let (n, mut l) = (it.next().unwrap(), it.next().unwrap());
    let mut heights: Vec<usize> = (0..n).map(|_| it.next().unwrap()).collect();
    heights.sort_unstable();
    for &height in heights.iter() {
        if height > l {
            break;
        }
        l += 1;
    }
    print!("{l}");
}