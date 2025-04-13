use std::io::{self, BufReader, Read};

#[derive(Clone)]
enum Direction {
    Vertical = 0,
    Horizontal = 1,
    Diagonal = 2,
}

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let map: Vec<Vec<bool>> = (0..n).map(|_| (0..n).map(|_| f() == 0).collect()).collect();
    let mut dp: Vec<Vec<[u32; 3]>> = vec![vec![[0; 3]; n]; n];
    dp[0][1][Direction::Horizontal as usize] = 1;

    let (v, h, d) = (
        Direction::Vertical as usize,
        Direction::Horizontal as usize,
        Direction::Diagonal as usize,
    );

    let n = map.len();

    for row in 0..n {
        for col in 0..n {
            let [v_count, h_count, d_count] = dp[row][col];

            if can_move_in_direction(&map, row, col, Direction::Vertical) {
                dp[row + 1][col][v] += v_count + d_count;
            }
            if can_move_in_direction(&map, row, col, Direction::Horizontal) {
                dp[row][col + 1][h] += h_count + d_count;
            }
            if can_move_in_direction(&map, row, col, Direction::Diagonal) {
                dp[row + 1][col + 1][d] += v_count + h_count + d_count;
            }
        }
    }

    print!("{}", dp[n - 1][n - 1].iter().sum::<u32>());
}

fn can_move_in_direction(map: &[Vec<bool>], row: usize, col: usize, direction: Direction) -> bool {
    let n = map.len();
    match direction {
        Direction::Vertical => row + 1 < n && map[row + 1][col],
        Direction::Horizontal => col + 1 < n && map[row][col + 1],
        Direction::Diagonal => {
            row + 1 < n
                && col + 1 < n
                && map[row][col + 1]
                && map[row + 1][col]
                && map[row + 1][col + 1]
        }
    }
}