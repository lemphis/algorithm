use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let k = input.next().unwrap();
    let mut arr = Vec::new();
    for _ in 0..n {
        let num = input.next().unwrap();
        arr.push(num);
    }
    arr.sort();
    arr.reverse();
    let ans = arr.get(k - 1).unwrap();
    println!("{ans}");
}
