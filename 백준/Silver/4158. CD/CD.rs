use std::{collections::HashSet, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut output = String::new();
    loop {
        let (n, m) = (input.next().unwrap(), input.next().unwrap());
        if n == 0 && m == 0 {
            break;
        }
        let mut n_set = HashSet::with_capacity(n);
        for _ in 0..n {
            n_set.insert(input.next().unwrap());
        }
        let mut m_set = HashSet::with_capacity(m);
        for _ in 0..n {
            m_set.insert(input.next().unwrap());
        }
        output.push_str(&format!(
            "{}\n",
            n_set.intersection(&m_set).collect::<Vec<_>>().len()
        ));
    }
    print!("{output}");
}