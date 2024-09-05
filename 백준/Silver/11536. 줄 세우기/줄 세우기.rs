use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace();
    let mut names = input.skip(1).enumerate().collect::<Vec<_>>();
    names.sort_by(|a, b| a.1.cmp(b.1));
    let mut is_increasing = true;
    for i in 0..names.len() {
        if names[i].0 != i {
            is_increasing = false;
            break;
        }
    }
    if is_increasing {
        print!("INCREASING");
        return;
    }
    let mut is_decreasing = true;
    for i in 0..names.len() {
        if names[i].0 != names.len() - 1 - i {
            is_decreasing = false;
            break;
        }
    }
    if is_decreasing {
        print!("DECREASING");
        return;
    }
    print!("NEITHER");
}