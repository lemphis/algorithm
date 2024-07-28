use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<i32>);
    let (n, k) = (it.next().unwrap() as usize, it.next().unwrap() as usize);
    let mut sensors = vec![0; n];
    for sensor in sensors.iter_mut() {
        *sensor = it.next().unwrap();
    }
    if k > n {
        print!("0");
        return;
    }
    sensors.sort_unstable();
    let mut diffs: Vec<i32> = sensors.windows(2).map(|w| w[1] - w[0]).collect();
    diffs.sort_by(|a, b| b.cmp(a));
    print!("{}", diffs.iter().skip(k - 1).sum::<i32>());
}