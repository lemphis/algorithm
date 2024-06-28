use std::{
    collections::VecDeque,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap() as usize;
    let mut ballons = VecDeque::with_capacity(n);
    for i in 0..n {
        ballons.push_back((input.next().unwrap(), i + 1));
    }
    let mut ans: Vec<usize> = Vec::with_capacity(n);
    for _ in 0..n - 1 {
        let ballon = ballons.pop_front().unwrap();
        ans.push(ballon.1);
        if ballon.0 < 0 {
            for _ in ballon.0..0 {
                let next_ballon = ballons.pop_back().unwrap();
                ballons.push_front(next_ballon);
            }
        } else {
            for _ in 0..ballon.0 - 1 {
                let next_ballon = ballons.pop_front().unwrap();
                ballons.push_back(next_ballon);
            }
        }
    }

    let mut output = String::new();
    for idx in ans {
        output.push_str(&format!("{} ", idx));
    }
    output.push_str(&format!("{}", ballons.pop_front().unwrap().1));

    print!("{output}");
}