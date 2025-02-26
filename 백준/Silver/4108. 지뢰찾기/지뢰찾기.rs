use std::io::{self, BufReader, Read};

const DIR: [(i32, i32); 8] = [
    (-1, 0),
    (-1, 1),
    (0, 1),
    (1, 1),
    (1, 0),
    (1, -1),
    (0, -1),
    (-1, -1),
];

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let mut output = String::with_capacity(1024);
    loop {
        let (r, c) = (f().parse::<usize>().unwrap(), f().parse::<usize>().unwrap());
        if r == 0 && c == 0 {
            break;
        }
        let mut map: Vec<Vec<_>> = (0..r).map(|_| f().chars().collect()).collect();
        for row in 0..r {
            for col in 0..c {
                if map[row][col] == '.' {
                    let mut mine_count = 0;
                    for (dr, dc) in DIR {
                        let (next_r, next_c) = (row as i32 + dr, col as i32 + dc);
                        if (0..r as i32).contains(&next_r)
                            && (0..c as i32).contains(&next_c)
                            && map[next_r as usize][next_c as usize] == '*'
                        {
                            mine_count += 1;
                        }
                    }
                    map[row][col] = char::from_digit(mine_count, 10).unwrap();
                }
            }
        }
        output.push_str(&format!(
            "{}\n",
            map.iter()
                .map(|r| String::from_iter(r.iter()))
                .collect::<Vec<String>>()
                .join("\n")
        ));
    }
    print!("{output}");
}