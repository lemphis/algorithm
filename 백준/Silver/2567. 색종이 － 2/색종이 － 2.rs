use std::io;

const DR: [i32; 4] = [0, 0, -1, 1];
const DC: [i32; 4] = [-1, 1, 0, 0];

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut board = vec![vec![false; 101]; 101];
    for _ in 0..n {
        let (c, r) = (input.next().unwrap(), input.next().unwrap());
        for i in r..r + 10 {
            for j in c..c + 10 {
                board[i][j] = true;
            }
        }
    }
    let mut count = 0;
    for r in 0..100 {
        for c in 0..100 {
            if board[r][c] {
                for i in 0..4 {
                    let next_r = r as i32 + DR[i];
                    let next_c = c as i32 + DC[i];
                    if (0..101).contains(&next_r)
                        && (0..101).contains(&next_c)
                        && !board[next_r as usize][next_c as usize]
                    {
                        count += 1;
                    }
                }
            }
        }
    }
    print!("{count}");
}