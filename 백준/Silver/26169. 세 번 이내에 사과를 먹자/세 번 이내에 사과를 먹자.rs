use std::io::{self, stdin};

const DIR: [(i32, i32); 4] = [(0, -1), (0, 1), (-1, 0), (1, 0)];

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut f = || input.next().unwrap();
    let mut map = [[0; 5]; 5];
    for r in map.iter_mut() {
        for block in r.iter_mut() {
            *block = f();
        }
    }
    let (r, c) = (f(), f());
    let mut ans = 0;
    dfs(&mut map, r as usize, c as usize, 0, 0, &mut ans);
    print!("{ans}");
}

fn dfs(
    map: &mut [[i32; 5]; 5],
    r: usize,
    c: usize,
    apple_count: i32,
    move_count: i32,
    ans: &mut i32,
) {
    if *ans == 1 {
        return;
    }
    if move_count == 3 {
        if apple_count >= 2 {
            *ans = 1;
        }
        return;
    }
    map[r][c] = -1;
    for &d in DIR.iter() {
        let (next_r, next_c) = (r as i32 + d.0, c as i32 + d.1);
        if (0..5).contains(&next_r) && (0..5).contains(&next_c) {
            let (r_usize, c_usize) = (next_r as usize, next_c as usize);
            match map[r_usize][c_usize] {
                -1 => continue,
                0 => {
                    map[r_usize][c_usize] = -1;
                    dfs(map, r_usize, c_usize, apple_count, move_count + 1, ans);
                    map[r_usize][c_usize] = 0;
                }
                1 => {
                    map[r_usize][c_usize] = -1;
                    dfs(map, r_usize, c_usize, apple_count + 1, move_count + 1, ans);
                    map[r_usize][c_usize] = 1;
                }
                _ => unreachable!(),
            }
        }
    }
}