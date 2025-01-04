use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, mut m) = (f(), f());
    let (mut count, mut min_mileages) = (0, Vec::new());
    for _ in 0..n {
        let (p, l) = (f(), f());
        if p < l {
            count += 1;
            m -= 1;
            (0..p).for_each(|_| {
                f();
            });
            if m == 0 {
                print!("{count}");
                return;
            }
        } else {
            let mut mileages = (0..p).map(|_| f()).collect::<Vec<_>>();
            mileages.sort();
            min_mileages.push(mileages[p - l]);
        }
    }
    min_mileages.sort();
    for &mileage in min_mileages.iter() {
        if m < mileage {
            break;
        }
        m -= mileage;
        count += 1;
    }
    print!("{count}");
}