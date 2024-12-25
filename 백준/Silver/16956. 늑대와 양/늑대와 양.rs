use std::io::{self, stdin};

const DR: [i32; 4] = [0, 1, 0, -1];
const DC: [i32; 4] = [-1, 0, 1, 0];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (r, c) = (f().parse::<usize>().unwrap(), f().parse::<usize>().unwrap());
    let mut map = (0..r)
        .map(|_| f().chars().collect::<Vec<_>>())
        .collect::<Vec<_>>();
    for row in 0..r {
        for col in 0..c {
            if map[row][col] == 'S' {
                let wrapped = wrap(&mut map, row, col);
                if !wrapped {
                    print!("0");
                    return;
                }
            }
        }
    }
    let mut output = String::with_capacity(r * c * 2);
    output.push_str("1\n");
    for row in map.iter() {
        for col in row.iter() {
            output.push(*col);
        }
        output.push('\n');
    }
    print!("{output}");
}

fn wrap(map: &mut [Vec<char>], row: usize, col: usize) -> bool {
    for i in 0..4 {
        let (r, c) = (row as i32 + DR[i], col as i32 + DC[i]);
        if is_in_bounds(map, r, c) {
            let (r, c) = (r as usize, c as usize);
            if map[r][c] == 'W' {
                return false;
            }
            if map[r][c] == '.' {
                map[r][c] = 'D';
            }
        }
    }
    true
}

#[inline]
fn is_in_bounds(map: &mut [Vec<char>], row: i32, col: i32) -> bool {
    row >= 0 && row < map.len() as i32 && col >= 0 && col < map[0].len() as i32
}