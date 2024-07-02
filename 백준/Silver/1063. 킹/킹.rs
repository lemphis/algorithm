use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let mut king = input.next().unwrap().chars().collect::<Vec<char>>();
    let mut stone = input.next().unwrap().chars().collect::<Vec<char>>();
    let n = input.next().unwrap().parse::<i32>().unwrap();
    for _ in 0..n {
        let command = input.next().unwrap();
        let (dr, dc) = match command {
            "R" => (0, 1),
            "L" => (0, -1),
            "B" => (-1, 0),
            "T" => (1, 0),
            "RT" => (1, 1),
            "LT" => (1, -1),
            "RB" => (-1, 1),
            "LB" => (-1, -1),
            _ => unreachable!(),
        };
        let king_r = king[1];
        let king_c = king[0];
        if (dr == 1 && king_r == '8')
            || (dr == -1 && king_r == '1')
            || (dc == -1 && king_c == 'A')
            || (dc == 1 && king_c == 'H')
        {
            continue;
        }
        let king_next_r = king_r as i32 + dr;
        let king_next_c = king_c as i32 + dc;
        let stone_r = stone[1];
        let stone_c = stone[0];
        if king_next_r == stone_r as i32 && king_next_c == stone_c as i32 {
            if (dr == 1 && stone_r == '8')
                || (dr == -1 && stone_r == '1')
                || (dc == -1 && stone_c == 'A')
                || (dc == 1 && stone_c == 'H')
            {
                continue;
            } else {
                let stone_next_r = stone_r as i32 + dr;
                let stone_next_c = stone_c as i32 + dc;
                let mut stone_next = stone.into_iter().collect::<Vec<char>>();
                stone_next[1] = (stone_next_r as u8) as char;
                stone_next[0] = (stone_next_c as u8) as char;
                stone = stone_next;
            }
        }
        let mut king_next = king.into_iter().collect::<Vec<char>>();
        king_next[1] = (king_next_r as u8) as char;
        king_next[0] = (king_next_c as u8) as char;
        king = king_next;
    }

    print!(
        "{}\n{}",
        king.iter().collect::<String>(),
        stone.iter().collect::<String>()
    )
}
