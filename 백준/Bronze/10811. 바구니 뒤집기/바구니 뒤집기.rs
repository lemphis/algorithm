use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut arr = Vec::new();
    for i in 0..n {
        arr.push(i + 1);
    }
    let m = input.next().unwrap();
    for _ in 0..m {
        let i = input.next().unwrap() - 1;
        let j = input.next().unwrap() - 1;
        for idx in 0..((j - i + 1) as f64 / 2.0).ceil() as usize {
            let temp: usize = arr[i + idx];
            arr[i + idx] = arr[j - idx];
            arr[j - idx] = temp;
        }
    }
    for i in 0..n {
        print!("{} ", arr[i]);
    }
}
