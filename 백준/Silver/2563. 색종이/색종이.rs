use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut is_paper = [[0; 100]; 100];
    for _ in 0..input.next().unwrap() {
        let (x, y) = (input.next().unwrap(), input.next().unwrap());
        for r in is_paper.iter_mut().skip(y).take(10) {
            r[x..x + 10].fill(1);
        }
    }
    let mut count = 0;
    for r in is_paper.iter() {
        count += r.iter().sum::<usize>();
    }
    print!("{count}");
}
