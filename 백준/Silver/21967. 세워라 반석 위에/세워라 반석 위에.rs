use std::{
    collections::VecDeque,
    io::{self, stdin},
};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums: Vec<_> = (0..n).map(|_| f()).collect();

    let (mut l, mut max_len) = (0, 0);
    let (mut max_deque, mut min_deque) = (VecDeque::new(), VecDeque::new());

    for r in 0..n {
        while let Some(&back) = min_deque.back() {
            if nums[r] > nums[back] {
                break;
            }
            min_deque.pop_back();
        }
        min_deque.push_back(r);

        while let Some(&back) = max_deque.back() {
            if nums[r] < nums[back] {
                break;
            }
            max_deque.pop_back();
        }
        max_deque.push_back(r);
        while nums[*max_deque.front().unwrap()] - nums[*min_deque.front().unwrap()] > 2 {
            if *max_deque.front().unwrap() == l {
                max_deque.pop_front();
            }
            if *min_deque.front().unwrap() == l {
                min_deque.pop_front();
            }
            l += 1;
        }

        max_len = max_len.max(r - l + 1);
    }

    print!("{max_len}");
}