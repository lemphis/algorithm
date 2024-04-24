use std::io::stdin;

fn main() {
    let mut input = String::new();
    let _ = stdin().read_line(&mut input);
    let n = input.trim().parse::<usize>().unwrap();
    for i in 0..n {
        let mut input = String::new();
        let _ = stdin().read_line(&mut input).unwrap();
        let mut arr = Vec::new();
        let strs = input.split_ascii_whitespace();
        for str in strs {
            arr.push(str);
        }
        let mut output = format!("Case #{}:", i + 1);
        for item in arr.iter().rev() {
            output.push_str(format!(" {}", item).as_str());
        }
        println!("{}", output);
    }
}