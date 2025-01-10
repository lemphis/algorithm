use std::{
    collections::VecDeque,
    io::{self, stdin},
};

const DIR: [(i32, i32); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let t = f().parse::<usize>().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let (h, _) = (f().parse::<usize>().unwrap(), f());
        let mut map = (0..h)
            .map(|_| f().chars().collect::<Vec<_>>())
            .collect::<Vec<_>>();
        let mut count = 0;
        for r in 0..h {
            for c in 0..map[r].len() {
                if map[r][c] == '#' {
                    erase(&mut map, r, c);
                    count += 1;
                }
            }
        }
        output.push_str(&format!("{count}\n"));
    }
    print!("{output}");
}

fn erase(map: &mut [Vec<char>], start_r: usize, start_c: usize) {
    let mut q = VecDeque::new();
    q.push_back((start_r, start_c));
    map[start_r][start_c] = '.';
    while let Some((r, c)) = q.pop_front() {
        for &(dr, dc) in DIR.iter() {
            let next_r = r as i32 + dr;
            let next_c = c as i32 + dc;
            if next_r >= 0
                && next_r < map.len() as i32
                && next_c >= 0
                && next_c < map[r].len() as i32
                && map[next_r as usize][next_c as usize] == '#'
            {
                map[next_r as usize][next_c as usize] = ',';
                q.push_back((next_r as usize, next_c as usize));
            }
        }
    }
}