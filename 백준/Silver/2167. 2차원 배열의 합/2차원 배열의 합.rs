use std::io::{self, Read};

fn main() {
    let mut input = String::with_capacity(1_000_000);
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<i32>);
    let (n, m) = (it.next().unwrap() as usize, it.next().unwrap() as usize);
    let mut arr = vec![vec![0; m]; n];
    for i in arr.iter_mut() {
        for j in i.iter_mut() {
            *j = it.next().unwrap();
        }
    }
    let k = it.next().unwrap();
    let mut output = String::with_capacity(200_000);
    for _ in 0..k {
        let (i, j, x, y) = (
            (it.next().unwrap() - 1) as usize,
            (it.next().unwrap() - 1) as usize,
            (it.next().unwrap() - 1) as usize,
            (it.next().unwrap() - 1) as usize,
        );
        let mut sum = 0;
        for row in arr.iter().take(x + 1).skip(i) {
            for item in row.iter().take(y + 1).skip(j) {
                sum += item;
            }
        }
        output.push_str(&format!("{sum}\n"));
    }
    print!("{output}");
}