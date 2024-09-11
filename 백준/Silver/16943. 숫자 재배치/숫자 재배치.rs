use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let (a, b) = (
        input.next().unwrap().chars().collect::<Vec<_>>(),
        input.next().unwrap().chars().collect::<Vec<_>>(),
    );
    if a.len() > b.len() {
        print!("-1");
        return;
    }
    let mut c = -1;
    let mut temp = Vec::new();
    let mut visited = vec![false; a.len()];
    dfs(
        &a,
        b.iter().collect::<String>().parse::<i32>().unwrap(),
        &mut c,
        &mut temp,
        &mut visited,
    );
    print!("{c}");
}

fn dfs(a: &Vec<char>, b: i32, c: &mut i32, temp: &mut Vec<char>, visited: &mut Vec<bool>) {
    if temp.len() == a.len() {
        if temp[0] == '0' {
            return;
        }
        let temp_num: i32 = temp.iter().collect::<String>().parse().unwrap();
        if b > temp_num {
            *c = (*c).max(temp_num);
        }
    }
    for i in 0..a.len() {
        if !visited[i] {
            temp.push(a[i]);
            visited[i] = true;
            dfs(a, b, c, temp, visited);
            temp.pop();
            visited[i] = false;
        }
    }
}