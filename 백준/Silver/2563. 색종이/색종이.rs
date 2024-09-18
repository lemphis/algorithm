use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut is_paper = [[false; 100]; 100];
    let papers = input
        .skip(1)
        .collect::<Vec<_>>()
        .chunks(2)
        .map(|c| (c[0], c[1]))
        .collect::<Vec<_>>();
    for &(x, y) in papers.iter() {
        for r in is_paper.iter_mut().skip(y).take(10) {
            for item in r.iter_mut().skip(x).take(10) {
                *item = true;
            }
        }
    }
    let mut count = 0;
    for r in is_paper.iter() {
        for item in r.iter() {
            if *item {
                count += 1;
            }
        }
    }
    print!("{count}");
}
