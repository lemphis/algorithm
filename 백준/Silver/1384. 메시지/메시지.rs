use std::io::{self};

fn main() {
    let mut tc = 1;
    let mut output = String::new();
    loop {
        let mut input = String::new();
        let _ = io::stdin().read_line(&mut input);
        let n = input
            .split_ascii_whitespace()
            .next()
            .unwrap()
            .parse::<usize>()
            .unwrap();
        if n == 0 {
            break;
        }
        output.push_str(&format!("Group {}\n", tc));
        let mut arr = vec![(String::new(), vec!['P'; n - 1]); n];
        for (name, chars) in arr.iter_mut() {
            let mut input = String::new();
            let _ = io::stdin().read_line(&mut input);
            let mut input = input.split_ascii_whitespace();
            *name = input.next().unwrap().to_string();
            for ch in chars.iter_mut().take(n - 1) {
                *ch = input.next().unwrap().parse::<char>().unwrap();
            }
        }
        let mut nasty_cnt = 0;
        for i in 0..n {
            for j in 0..n - 1 {
                if arr[i].1[j] == 'N' {
                    let i_idx = i as i32;
                    let j_idx = j as i32;
                    let target_idx = if i_idx - (j_idx + 1) < 0 {
                        n as i32 + i_idx - (j_idx + 1)
                    } else {
                        i_idx - (j_idx + 1)
                    };
                    output.push_str(&format!(
                        "{} was nasty about {}\n",
                        arr[target_idx as usize].0, arr[i].0
                    ));
                    nasty_cnt += 1;
                }
            }
        }
        if nasty_cnt == 0 {
            output.push_str("Nobody was nasty\n");
        }
        output.push('\n');
        tc += 1;
    }
    print!("{output}");
}