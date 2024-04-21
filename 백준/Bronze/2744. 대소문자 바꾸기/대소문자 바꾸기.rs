use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut output = String::new();
    for c in input.chars() {
        if c.is_uppercase() {
            output.push(c.to_lowercase().next().unwrap());
        } else {
            output.push(c.to_uppercase().next().unwrap());
        }
    }
    print!("{}", output);
}