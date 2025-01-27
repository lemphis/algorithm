use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    if n < 3 {
        print!("0");
        return;
    }
    let mut count = 0;
    for i in 1..n {
        for j in i..n {
            let k = n.saturating_sub(i).saturating_sub(j);
            if k == 0 || j > k {
                break;
            }
            if i + j > k {
                count += 1;
            }
        }
    }
    print!("{count}");
}