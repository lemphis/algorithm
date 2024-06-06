use std::io;

fn main() {
    let vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    loop {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let _ = input.split_ascii_whitespace();
        if input.contains("#") {
            break;
        }
        println!("{}", input.chars().filter(|&c| vowels.contains(&c)).count());
    }
}
