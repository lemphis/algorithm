use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut arr = [0; 100];
    let m = input.next().unwrap();
    for _ in 0..m {
        let i = input.next().unwrap();
        let j = input.next().unwrap();
        let k = input.next().unwrap();
        for idx in i..=j {
            arr[idx - 1] = k
        }
    }
    for i in 0..n {
        print!("{} ", arr[i]);
    }
}
