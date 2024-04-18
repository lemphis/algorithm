use std::collections::HashMap;
use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse().unwrap();
    let mut map = HashMap::new();
    let mut count = 0;
    for _ in 0..n {
        let message = input.next().unwrap();
        match message {
            "ENTER" => map.clear(),
            id => {
                if !map.contains_key(id) {
                    map.insert(id, 1);
                    count += 1;
                }
            }
        }
    }
    print!("{count}");
}
