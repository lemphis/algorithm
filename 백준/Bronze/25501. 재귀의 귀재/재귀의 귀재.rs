use std::io::stdin;

fn main() {
    let mut input = String::new();
    read_one_line(&mut input);
    let t = input.trim().parse().unwrap();
    for _ in 0..t {
        input = String::new();
        let mut call_cnt = 0;
        read_one_line(&mut input);
        let palindrome = is_palindrome(&input.trim().to_string(), &mut call_cnt);
        println!("{} {}", palindrome as usize, call_cnt);
    }
}

fn read_one_line(str: &mut String) {
    stdin().read_line(str).unwrap();
}

fn is_palindrome(str: &String, call_cnt: &mut usize) -> bool {
    return check_palindrome(str, 0, str.len() - 1, call_cnt);
}

fn check_palindrome(str: &String, l_idx: usize, r_idx: usize, call_cnt: &mut usize) -> bool {
    *call_cnt += 1;
    if l_idx >= r_idx {
        true
    } else if str.chars().nth(l_idx) != str.chars().nth(r_idx) {
        false
    } else {
        check_palindrome(str, l_idx + 1, r_idx - 1, call_cnt)
    }
}