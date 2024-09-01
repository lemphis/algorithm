use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let (a, b) = (input.next().unwrap(), input.next().unwrap());
    let alphabet = [
        3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1,
    ];
    let mut nums = a
        .chars()
        .zip(b.chars())
        .flat_map(|(a1, b1)| {
            vec![
                alphabet[(a1 as u8 - b'A') as usize],
                alphabet[(b1 as u8 - b'A') as usize],
            ]
        })
        .collect::<Vec<_>>();
    while nums.len() > 2 {
        nums = nums.windows(2).map(|w| (w[0] + w[1]) % 10).collect();
    }
    print!("{}{}", nums[0], nums[1]);
}