use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for i in 0..t {
        let (p, q) = (f(), f());
        let mut dp = vec![0; p + 2];
        dp[1] = 1;
        dp[2] = 1;
        for i in 3..=p {
            dp[i] = (dp[i - 1] + dp[i - 2]) % q;
        }
        output.push_str(&format!("Case #{}: {}\n", i + 1, dp[p] % q));
    }
    print!("{output}");
}