use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let (h, w) = (
        input.next().unwrap().parse::<usize>().unwrap(),
        input.next().unwrap().parse::<usize>().unwrap(),
    );
    let mut map = vec![vec!['.'; w]; h];
    for map_line in map.iter_mut() {
        *map_line = input.next().unwrap().chars().collect();
    }
    let mut ans = vec![vec![-1; w]; h];
    for r in 0..h {
        for c in 0..w {
            if map[r][c] == '.' {
                if c > 0 && ans[r][c - 1] > -1 {
                    ans[r][c] = ans[r][c - 1] + 1;
                }
            } else {
                ans[r][c] = 0;
            }
        }
    }
    let mut output = String::new();
    for line in ans.iter() {
        for ch in line.iter() {
            output.push_str(&format!("{ch} "));
        }
        output.push('\n');
    }
    print!("{output}");
}