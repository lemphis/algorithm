use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let input = buf.split_ascii_whitespace();
    let mut nums: Vec<u32> = Vec::with_capacity(1_000_000);
    for i in 1.. {
        if nums.capacity() == nums.len() {
            break;
        }
        let mut mask = 0;
        let mut temp = i;
        let mut pass = true;
        while temp > 0 {
            let q = temp % 10;
            let bit = 1 << q;
            if mask & bit > 0 {
                pass = false;
                break;
            }
            mask |= bit;
            temp /= 10;
        }
        if pass {
            nums.push(i);
        }
    }

    let mut output = String::new();
    for n in input {
        let n: usize = n.parse().unwrap();
        if n == 0 {
            break;
        }
        output.push_str(&format!("{}\n", nums[n - 1]));
    }
    print!("{output}");
}