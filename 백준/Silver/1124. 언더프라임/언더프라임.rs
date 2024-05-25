use std::io::{self};

const MAX: usize = 100_001;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut line = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let a = line.next().unwrap();
    let b = line.next().unwrap();
    let mut is_prime = [true; MAX];
    is_prime[0] = false;
    is_prime[1] = false;
    let mut prime_cnts = [0; MAX];
    for i in 2..=MAX / 2 {
        if is_prime[i] {
            let mut times = 2;
            while i * times < MAX {
                is_prime[i * times] = false;
                let mut cnt = 1;
                let mut temp = times;
                while temp % i == 0 {
                    temp /= i;
                    cnt += 1;
                }
                prime_cnts[i * times] += cnt;
                times += 1;
            }
        }
    }
    let mut ans = 0;
    for i in a..=b {
        if is_prime[prime_cnts[i]] {
            ans += 1;
        }
    }
    print!("{}", ans);
}