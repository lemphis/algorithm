use std::io::{self, Read};

const MAX: usize = 100_001;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let k = input.next().unwrap();
    let mut is_prime = [true; MAX];
    let mut primes = [0; MAX];
    for (i, elem) in primes.iter_mut().enumerate() {
        *elem = i;
    }
    primes[1] = 1;
    for i in 2..MAX {
        let mut times = 1;
        if is_prime[i] {
            while i * times < MAX {
                is_prime[i * times] = false;
                primes[i * times] = i;
                times += 1;
            }
        }
    }
    print!(
        "{}",
        primes
            .iter()
            .take(n + 1)
            .skip(1)
            .filter(|&&x| x <= k)
            .count()
    );
}