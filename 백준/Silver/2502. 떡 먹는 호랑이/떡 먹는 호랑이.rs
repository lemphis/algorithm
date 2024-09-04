use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let (d, k) = (input.next().unwrap(), input.next().unwrap());
    let mut output = String::new();
    let (mut a, mut b) = (k / 2, k / 2);
    if k & 1 == 1 {
        b += 1;
    }
    loop {
        let mut tmp_a = a;
        let mut tmp_b = b;
        for _ in 0..d - 3 {
            let tmp = tmp_a;
            tmp_a = tmp_b - tmp_a;
            tmp_b = tmp;
        }
        if tmp_a > 0 && tmp_b >= tmp_a {
            output.push_str(&format!("{}\n{}", tmp_a, tmp_b));
            break;
        }
        a -= 1;
        b += 1;
    }
    print!("{output}");
}