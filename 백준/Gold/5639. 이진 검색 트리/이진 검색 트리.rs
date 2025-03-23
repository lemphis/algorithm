use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(50000);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut preorder = Vec::new();
    for num in input {
        preorder.push(num);
    }

    traverse(&preorder, 0, preorder.len());
}

fn traverse(preorder: &[usize], start: usize, end: usize) {
    if start >= end {
        return;
    }

    let mut mid = start + 1;
    while mid < end && preorder[start] > preorder[mid] {
        mid += 1;
    }

    traverse(preorder, start + 1, mid);
    traverse(preorder, mid, end);

    println!("{}", preorder[start]);
}