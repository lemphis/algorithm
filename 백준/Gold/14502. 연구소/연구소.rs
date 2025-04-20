use std::{
    collections::VecDeque,
    io::{self, BufReader, Read},
};

const DIR: [(i32, i32); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let mut map = vec![vec![0; m]; n];
    let mut virus = Vec::new();
    let mut empty_area = Vec::new();
    for r in 0..n {
        for c in 0..m {
            map[r][c] = f();
            if map[r][c] == 0 {
                empty_area.push((r, c));
            } else if map[r][c] == 2 {
                virus.push((r, c));
            }
        }
    }

    let mut max_count = 0;
    let len = empty_area.len();
    for i in 0..len - 2 {
        map[empty_area[i].0][empty_area[i].1] = 1;
        for j in i + 1..len - 1 {
            map[empty_area[j].0][empty_area[j].1] = 1;
            for k in j + 1..len {
                map[empty_area[k].0][empty_area[k].1] = 1;
                let mut temp = map.clone();
                spread_virus(&mut temp, &virus);
                max_count = max_count.max(count_safe_area(&temp));
                map[empty_area[k].0][empty_area[k].1] = 0;
            }
            map[empty_area[j].0][empty_area[j].1] = 0;
        }
        map[empty_area[i].0][empty_area[i].1] = 0;
    }

    print!("{max_count}");
}

fn spread_virus(map: &mut [Vec<usize>], virus: &Vec<(usize, usize)>) {
    let (row, col) = (map.len(), map[0].len());
    let mut q = VecDeque::from_iter((*virus).clone());
    while let Some((r, c)) = q.pop_front() {
        for i in 0..4 {
            let (next_r, next_c) = (r as i32 + DIR[i].0, c as i32 + DIR[i].1);
            if (0..row as i32).contains(&next_r)
                && (0..col as i32).contains(&next_c)
                && map[next_r as usize][next_c as usize] == 0
            {
                map[next_r as usize][next_c as usize] = 2;
                q.push_back((next_r as usize, next_c as usize));
            }
        }
    }
}

fn count_safe_area(map: &[Vec<usize>]) -> usize {
    let mut count = 0;
    for r in 0..map.len() {
        for c in 0..map[0].len() {
            if map[r][c] == 0 {
                count += 1;
            }
        }
    }

    count
}