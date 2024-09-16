use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap() as usize;
    let mut nums = vec![0; n];
    for num in nums.iter_mut() {
        let (c, k) = (input.next().unwrap(), input.next().unwrap());
        *num = c * k;
    }
    println!("{}", nums.iter().fold(0, |acc, cur| acc + cur));
}