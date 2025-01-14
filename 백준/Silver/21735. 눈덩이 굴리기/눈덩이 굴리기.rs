use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut sizes = vec![1; n + 1];
    for size in sizes.iter_mut().skip(1) {
        *size = f();
    }
    let mut max_size = sizes[0];
    dfs(&sizes, 0, 0, m, sizes[0], &mut max_size);
    print!("{max_size}");
}

fn dfs(
    sizes: &[usize],
    start: usize,
    times: usize,
    max_times: usize,
    size: usize,
    max_size: &mut usize,
) {
    if start == sizes.len() || times == max_times {
        return;
    }
    if times < max_times {
        if start + 1 < sizes.len() {
            *max_size = (*max_size).max(size + sizes[start + 1]);
            dfs(
                sizes,
                start + 1,
                times + 1,
                max_times,
                size + sizes[start + 1],
                max_size,
            );
        }
        if start + 2 < sizes.len() {
            *max_size = (*max_size).max(size / 2 + sizes[start + 2]);
            dfs(
                sizes,
                start + 2,
                times + 1,
                max_times,
                size / 2 + sizes[start + 2],
                max_size,
            );
        }
    }
}