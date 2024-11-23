use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i64>);
    let mut f = || input.next().unwrap();
    let n = f() as usize;
    let mut nums = vec![0; n];
    let (mut total_sum, mut ans) = (0, 0);
    for num in nums.iter_mut() {
        *num = f();
        total_sum += *num;
    }
    for &num in nums.iter() {
        total_sum -= num;
        ans += total_sum * num;
    }
    print!("{ans}");
}