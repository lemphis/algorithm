use std::io::{self, stdin};

const DR: [i32; 8] = [-1, -1, 0, 1, 1, 1, 0, -1];
const DC: [i32; 8] = [0, 1, 1, 1, 0, -1, -1, -1];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<i32>().unwrap();
    let map = (0..n)
        .map(|_| input.next().unwrap().chars().collect::<Vec<_>>())
        .collect::<Vec<_>>();
    let mut count = (0..n).map(|_| vec![0; n as usize]).collect::<Vec<_>>();
    for r in 0..n {
        for c in 0..n {
            if map[r as usize][c as usize] != '.' {
                count[r as usize][c as usize] = i32::MIN;
                for i in 0..8 {
                    if r + DR[i] < n && r + DR[i] >= 0 && c + DC[i] < n && c + DC[i] >= 0 {
                        count[(r + DR[i]) as usize][(c + DC[i]) as usize] +=
                            map[r as usize][c as usize].to_digit(10).unwrap() as i32;
                    }
                }
            }
        }
    }
    let mut output = String::new();
    for r in count {
        for &item in r.iter() {
            output.push(match item {
                item if item > 9 => 'M',
                item if item < 0 => '*',
                _ => char::from_digit(item as u32, 10).unwrap(),
            });
        }
        output.push('\n');
    }
    print!("{output}");
}