use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut arr = Vec::<usize>::new();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    for i in 0..n {
        arr.push(i + 1);
    }
    let m = input.next().unwrap();
    for _ in 0..m {
        let i = input.next().unwrap();
        let j = input.next().unwrap();
        let temp = arr[i - 1];
        arr[i - 1] = arr[j - 1];
        arr[j - 1] = temp;
    }
    for i in 0..n {
        print!("{} ", arr[i]);
    }
}
