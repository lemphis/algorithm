use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut st = Vec::new();
    let mut item_idx = 1;
    for _ in 0..n {
        let order = input.next().unwrap();
        if order == item_idx {
            item_idx += 1;
        } else {
            st.push(order);
        }
        while !st.is_empty() && *st.last().unwrap() == item_idx {
            item_idx += 1;
            st.pop();
        }
    }
    while !st.is_empty() && *st.first().unwrap() == item_idx {
        item_idx += 1;
        st.pop();
    }
    print!("{}", if st.is_empty() { "Nice" } else { "Sad" });
}
