use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let (_, m, _) = (
        input.next().unwrap(),
        input.next().unwrap(),
        input.next().unwrap(),
    );
    let pos = input.collect::<Vec<_>>();
    let mut now_pos = 1;
    let mut move_count = 0;
    for &p in pos.iter() {
        if now_pos + m - 1 < p {
            move_count += p - (now_pos + m - 1);
            now_pos += p - (now_pos + m - 1)
        }
        if now_pos > p {
            move_count += now_pos - p;
            now_pos = p;
        }
    }
    print!("{move_count}");
}