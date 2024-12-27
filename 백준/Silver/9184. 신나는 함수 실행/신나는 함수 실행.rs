use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let mut output = String::new();
    let mut dp = [[[i32::MIN; 21]; 21]; 21];
    loop {
        let (a, b, c) = (f(), f(), f());
        if a == -1 && b == -1 && c == -1 {
            break;
        }
        output.push_str(&format!(
            "w({}, {}, {}) = {}\n",
            a,
            b,
            c,
            w(&mut dp, a, b, c)
        ));
    }
    print!("{output}");
}

fn w(dp: &mut [[[i32; 21]; 21]; 21], a: i32, b: i32, c: i32) -> i32 {
    if a <= 0 || b <= 0 || c <= 0 {
        return 1;
    }
    if a > 20 || b > 20 || c > 20 {
        return w(dp, 20, 20, 20);
    }
    if dp[a as usize][b as usize][c as usize] == i32::MIN {
        dp[a as usize][b as usize][c as usize] = if a < b && b < c {
            w(dp, a, b, c - 1) + w(dp, a, b - 1, c - 1) - w(dp, a, b - 1, c)
        } else {
            w(dp, a - 1, b, c) + w(dp, a - 1, b - 1, c) + w(dp, a - 1, b, c - 1)
                - w(dp, a - 1, b - 1, c - 1)
        }
    }
    dp[a as usize][b as usize][c as usize]
}