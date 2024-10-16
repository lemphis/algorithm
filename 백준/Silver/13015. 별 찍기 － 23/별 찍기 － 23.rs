use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut output = String::new();
    side(n, &mut output);
    top_middle(n, &mut output);
    center(n, &mut output);
    bottom_middle(n, &mut output);
    side(n, &mut output);
    print!("{output}");
}

fn side(n: usize, output: &mut String) {
    for _ in 0..n {
        output.push('*');
    }
    for _ in 0..(n - 1) * 2 - 1 {
        output.push(' ');
    }
    for _ in 0..n {
        output.push('*');
    }
    output.push('\n');
}

fn top_middle(n: usize, output: &mut String) {
    for r in 1..=n - 2 {
        for _ in 0..r {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..n - 2 {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..(n - 1) * 2 - 1 - (r * 2) {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..n - 2 {
            output.push(' ');
        }
        output.push('*');
        output.push('\n');
    }
}

fn center(n: usize, output: &mut String) {
    for _ in 0..n - 1 {
        output.push(' ');
    }
    output.push('*');
    for _ in 0..n - 2 {
        output.push(' ');
    }
    output.push('*');
    for _ in 0..n - 2 {
        output.push(' ');
    }
    output.push('*');
    output.push('\n');
}

fn bottom_middle(n: usize, output: &mut String) {
    for r in (1..=n - 2).rev() {
        for _ in 0..r {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..n - 2 {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..(n - 1) * 2 - 1 - (r * 2) {
            output.push(' ');
        }
        output.push('*');
        for _ in 0..n - 2 {
            output.push(' ');
        }
        output.push('*');
        output.push('\n');
    }
}
