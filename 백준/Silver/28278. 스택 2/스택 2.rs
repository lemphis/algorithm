use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap();
    let mut stack = Stack::new();
    let mut ans = String::new();
    for _ in 0..n {
        match input.next().unwrap() {
            1 => stack.push(input.next().unwrap()),
            2 => ans.push_str(&format!("{}{}", &stack.pop().to_string(), "\n")),
            3 => ans.push_str(&format!("{}{}", stack.size(), "\n")),
            4 => ans.push_str(&format!("{}{}", if stack.is_empty() { 1 } else { 0 }, "\n")),
            5 => ans.push_str(&format!("{}{}", stack.last(), "\n")),
            _ => (),
        }
    }
    println!("{}", ans);
}

struct Stack {
    items: Vec<i32>,
}

impl Stack {
    fn new() -> Stack {
        Stack { items: Vec::new() }
    }
}

impl Stack {
    fn push(&mut self, item: i32) {
        self.items.push(item);
    }
    fn pop(&mut self) -> i32 {
        let last = self.last();
        if last > -1 {
            self.items.pop();
        };
        last
    }
    fn size(&self) -> usize {
        self.items.len()
    }
    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
    fn last(&self) -> i32 {
        let last = self.items.last();
        match last {
            Some(item) => *item,
            None => -1,
        }
    }
}
