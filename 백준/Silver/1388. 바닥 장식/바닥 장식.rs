use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace();
    let board = input
        .skip(2)
        .map(|s| s.chars().collect::<Vec<_>>())
        .collect::<Vec<_>>();
    let mut visited = vec![vec![false; board[0].len()]; board.len()];
    let mut count = 0;
    for r in 0..board.len() {
        for c in 0..board[r].len() {
            if !visited[r][c] {
                if board[r][c] == '-' {
                    for i in c..board[r].len() {
                        if board[r][i] == '|' {
                            break;
                        }
                        visited[r][i] = true;
                    }
                } else {
                    for i in r..board.len() {
                        if board[i][c] == '-' {
                            break;
                        }
                        visited[i][c] = true;
                    }
                }
                count += 1;
            }
        }
    }
    print!("{count}");
}