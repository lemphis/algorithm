use std::io::{self};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut line = input.split_ascii_whitespace();
    let n = line.next().unwrap().parse::<usize>().unwrap();
    let mut room = vec![vec![true; n]; n];
    for item in room.iter_mut().take(n) {
        input.clear();
        let _ = io::stdin().read_line(&mut input);
        for (j, ch) in input.chars().enumerate().take(n) {
            item[j] = ch != 'X';
        }
    }
    let mut width_cnt = 0;
    for item in room.iter() {
        width_cnt += item
            .split(|x| *x == false)
            .map(|x| x.len())
            .filter(|x| *x > 1)
            .count();
    }
    let mut height_cnt = 0;
    for i in 0..n {
        let mut can_lay_down_cnt = 0;
        for j in 0..n {
            if room[j][i] {
                can_lay_down_cnt += 1;
            } else {
                can_lay_down_cnt = 0;
            }
            if can_lay_down_cnt == 2 {
                height_cnt += 1;
            }
        }
    }
    print!("{} {}", width_cnt, height_cnt);
}