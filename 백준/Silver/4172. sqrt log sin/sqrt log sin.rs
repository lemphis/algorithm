use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let mut dp = [0; 1_000_001];
    dp[0] = 1;
    for i in 1..1_000_000 {
        let i_f64 = i as f64;
        dp[i] = (dp[(i_f64 - i_f64.sqrt()) as usize]
            + dp[i_f64.ln() as usize]
            + dp[(i_f64 * i_f64.sin().powi(2)) as usize])
            % 1_000_000;
    }

    let mut output = String::new();
    loop {
        let n = f();
        if n == -1 {
            break;
        }
        output.push_str(&format!("{}\n", dp[n as usize]));
    }

    print!("{output}");
}