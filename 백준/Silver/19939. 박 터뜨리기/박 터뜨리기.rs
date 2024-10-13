use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let (n, k) = (input.next().unwrap(), input.next().unwrap());
    let min = k * (k + 1) / 2;
    print!(
        "{}",
        if min > n {
            -1
        } else {
            if (n - min) % k == 0 {
                k - 1
            } else {
                k
            }
        }
    );
}