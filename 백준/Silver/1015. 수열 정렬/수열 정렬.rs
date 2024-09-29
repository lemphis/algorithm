use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut permutation = input.enumerate().collect::<Vec<_>>();
    permutation.sort_by(|a, b| {
        if a.1 == b.1 {
            a.0.cmp(&b.0)
        } else {
            a.1.cmp(&b.1)
        }
    });
    let mut ans = vec![0; n];
    for i in 0..n {
        ans[permutation[i].0] = i;
    }
    for item in ans {
        print!("{} ", item);
    }
}