use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for _ in 0..t {
        let n = f();
        let prices = (0..n).map(|_| f()).collect::<Vec<_>>();
        let mut st = Vec::from([(prices[n - 1], n - 1)]);
        let mut revenue = 0;
        for (i, &price) in prices.iter().enumerate().rev().skip(1) {
            if st.last().unwrap().0 < price {
                st.push((price, i));
            }
        }
        let mut idx = 0;
        while !st.is_empty() {
            let last = st.last().unwrap();
            if last.1 > idx {
                revenue += last.0 - prices[idx];
            } else {
                st.pop();
            }
            idx += 1;
        }
        output.push_str(&format!("{revenue}\n"));
    }
    print!("{output}");
}