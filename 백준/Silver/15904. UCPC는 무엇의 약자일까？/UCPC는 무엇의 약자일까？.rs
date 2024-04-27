use std::io::stdin;

fn main() {
    let mut input = String::new();
    let _ = stdin().read_line(&mut input);
    let input = input.split_ascii_whitespace().collect::<String>();
    let chars = ['U', 'C', 'P', 'C'];
    let mut idx = 0;
    for ch in input.chars() {
        if ch == chars[idx] {
            idx += 1;
        }
        if idx == chars.len() {
            break;
        }
    }
    print!(
        "I {} UCPC",
        if idx == chars.len() { "love" } else { "hate" }
    );
}
