use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let tc = it.next().unwrap();
    for _ in 0..tc {
        let mut n = it.next().unwrap();
        loop {
            if is_prime(n) {
                println!("{}", n);
                break;
            }
            n += 1;
        }
    }
}

fn is_prime(n: usize) -> bool {
    match n {
        0..=1 => false,
        2..=3 => true,
        x if x % 2 == 0 || x % 3 == 0 => false,
        x => {
            for i in 5..=(x as f64).sqrt() as usize {
                if x % i == 0 {
                    return false;
                }
            }
            true
        }
    }
}