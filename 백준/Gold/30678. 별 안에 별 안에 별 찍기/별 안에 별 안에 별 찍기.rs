use std::io::{self, stdin};

const STAR_POINT: [(usize, usize); 12] = [
    (0, 2),
    (1, 2),
    (2, 0),
    (2, 1),
    (2, 2),
    (2, 3),
    (2, 4),
    (3, 1),
    (3, 2),
    (3, 3),
    (4, 1),
    (4, 3),
];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<u32>);
    let n = input.next().unwrap();
    if n == 0 {
        print!("*");
        return;
    }
    let size = 5usize.pow(n);
    let mut board = vec![vec![false; size]; size];
    draw(&mut board, n, 0, 0);
    let mut output = String::with_capacity(size * size);
    for row in board.iter_mut() {
        for is_star in row.iter_mut() {
            output.push(if *is_star { '*' } else { ' ' });
        }
        output.push('\n');
    }
    print!("{output}");
}

fn draw(board: &mut [Vec<bool>], times: u32, r: usize, c: usize) {
    if times == 1 {
        STAR_POINT
            .iter()
            .for_each(|&(dr, dc)| board[r + dr][c + dc] = true);
        return;
    }
    let mul = 5usize.pow(times - 1);
    STAR_POINT
        .iter()
        .for_each(|&(dr, dc)| draw(board, times - 1, mul * dr + r, mul * dc + c));
}