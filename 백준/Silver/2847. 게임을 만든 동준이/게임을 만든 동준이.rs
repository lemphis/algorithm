use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut levels = input.skip(1).collect::<Vec<_>>();
    let mut diff = 0;
    for i in (0..levels.len() - 1).rev() {
        if levels[i] >= levels[i + 1] {
            diff += levels[i] - levels[i + 1] + 1;
            levels[i] = levels[i + 1] - 1;
        }
    }
    print!("{diff}");
}