use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut ans = 0;
    for i in 1..=n {
        let (mut temp, mut sum) = (i, i);
        while temp > 0 {
            sum += temp % 10;
            temp /= 10;
        }
        if n == sum {
            ans = i;
            break;
        }
    }
    print!("{ans}");
}