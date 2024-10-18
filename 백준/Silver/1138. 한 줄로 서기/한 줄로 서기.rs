use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut ans = vec![0; n];
    for height in 1..=n {
        let mut count = input.next().unwrap();
        for order in ans.iter_mut() {
            if *order == 0 {
                if count == 0 {
                    *order = height;
                    break;
                }
                count -= 1;
            }
        }
    }
    print!(
        "{}",
        ans.iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
