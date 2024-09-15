use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut is_prime = [true; 10_001];
    is_prime[1] = false;
    for i in 2..10_001 {
        if is_prime[i] {
            let mut times = 2;
            while i * times < 10_001 {
                is_prime[i * times] = false;
                times += 1;
            }
        }
    }
    print!(
        "{}",
        is_prime
            .iter()
            .enumerate()
            .filter(|&(_, prime)| *prime)
            .map(|(i, _)| i)
            .collect::<Vec<usize>>()
            .windows(2)
            .find(|&w| w[0] * w[1] > n)
            .unwrap()
            .iter()
            .product::<usize>()
    );
}