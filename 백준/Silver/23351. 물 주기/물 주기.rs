use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k, a, b) = (f(), f(), f(), f());
    let mut pots = vec![k; n];
    let mut time = 0;
    loop {
        let (min_idx, &min) = pots
            .iter()
            .enumerate()
            .min_by_key(|&(_, &value)| value)
            .unwrap();
        if min == 0 {
            break;
        }
        for i in min_idx.min(n - a + 1)..(min_idx + a).min(n) {
            pots[i] += b;
        }
        for pot in pots.iter_mut() {
            *pot -= 1;
        }
        time += 1;
    }
    print!("{time}");
}