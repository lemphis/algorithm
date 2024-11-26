use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut output = String::new();
    while let (Some(n), Some(m)) = (input.next(), input.next()) {
        let mut count = 0;
        for i in n..=m {
            let mut check = true;
            let i = i.to_string();
            let mut is_checked = [false; 10];
            for c in i.chars() {
                let num = c.to_digit(10).unwrap() as usize;
                if is_checked[num] {
                    check = false;
                    break;
                }
                is_checked[num] = true;
            }
            if check {
                count += 1;
            }
        }
        output.push_str(&format!("{count}\n"));
    }
    print!("{output}");
}