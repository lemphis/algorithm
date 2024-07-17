use std::{
    cmp::min,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let (n, m) = {
        let mut it = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
        (it.next().unwrap(), it.next().unwrap())
    };
    print!(
        "{}",
        match n {
            1 => 1,
            2 => min(4, (m + 1) / 2),
            3.. => {
                if m < 7 {
                    min(4, m)
                } else {
                    m - 2
                }
            }
            _ => unreachable!(),
        }
    );
}