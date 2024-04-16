use std::io::{stdin, Read};
use std::process::exit;

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut arr = Vec::new();
    for _ in 0..6 {
        arr.push(input.next().unwrap());
    }
    for x in -999..=999 {
        for y in -999..=999 {
            if ((arr[0] * x) + (arr[1] * y) == arr[2]) && ((arr[3] * x) + (arr[4] * y) == arr[5]) {
                println!("{} {}", x, y);
                exit(0);
            }
        }
    }
}
