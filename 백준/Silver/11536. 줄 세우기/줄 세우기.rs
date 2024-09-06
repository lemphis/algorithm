use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace();
    let names = input.skip(1).collect::<Vec<_>>();
    if (0..names.len() - 1).all(|i| names[i] < names[i + 1]) {
        print!("INCREASING");
        return;
    }
    if (0..names.len() - 1).all(|i| names[i] > names[i + 1]) {
        print!("DECREASING");
        return;
    }
    print!("NEITHER");
}