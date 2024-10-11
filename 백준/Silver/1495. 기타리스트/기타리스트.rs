use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (n, s, m) = (
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
    );
    let volumes = input.collect::<Vec<_>>();
    let mut dp = vec![vec![false; m as usize + 1]; n as usize];
    dfs(&volumes, 0, s, m, &mut dp);
    let mut max = -1;
    for i in 0..=m {
        if dp[n as usize - 1][i as usize] {
            max = i;
        }
    }
    print!("{max}");
}

fn dfs(volumes: &[i32], depth: usize, sum: i32, m: i32, dp: &mut [Vec<bool>]) {
    if sum > m || sum < 0 {
        return;
    }
    if volumes.len() == depth {
        dp[depth - 1][sum as usize] = true;
        return;
    }
    if sum + volumes[depth] <= m && !dp[depth][(sum + volumes[depth]) as usize] {
        dp[depth][(sum + volumes[depth]) as usize] = true;
        dfs(volumes, depth + 1, sum + volumes[depth], m, dp)
    }
    if sum - volumes[depth] >= 0 && !dp[depth][(sum - volumes[depth]) as usize] {
        dp[depth][(sum - volumes[depth]) as usize] = true;
        dfs(volumes, depth + 1, sum - volumes[depth], m, dp)
    }
}