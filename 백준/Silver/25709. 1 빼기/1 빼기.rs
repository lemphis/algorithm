use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<i32>().unwrap();
    print!("{}", min_operations(n));
}

fn min_operations(mut n: i32) -> i32 {
    let mut operations = 0;
    while n > 0 {
        if let Some(pos) = n.to_string().find('1') {
            let mut s = n.to_string();
            s.remove(pos);
            n = s.parse().unwrap_or(0);
        } else {
            n -= 1;
        }
        operations += 1;
    }
    operations
}