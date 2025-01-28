use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();

    let (n, m, b) = (f(), f(), f());
    let mut map: Vec<usize> = (0..n * m).map(|_| f()).collect();

    map.sort_unstable();

    let (mut min_time, mut max_len) = (usize::MAX, map[0]);
    for i in map[0]..=map[n * m - 1] {
        let mut count = 0;
        let mut inven = b as i32;
        for &num in map.iter().rev() {
            if i < num {
                count += (num - i) * 2;
                inven += (num - i) as i32;
            } else if i > num {
                count += i - num;
                inven -= (i - num) as i32;
            }
        }
        if inven < 0 {
            continue;
        }
        if min_time >= count {
            min_time = count;
            max_len = i;
        }
    }

    print!("{min_time} {max_len}");
}