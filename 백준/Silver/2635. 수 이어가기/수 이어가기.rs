use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<i32>);
    let n = input.next().unwrap();
    let mut max_count = 0;
    let mut nums = Vec::new();
    for num in 1..=n {
        let mut temp = Vec::new();
        temp.push(n);
        temp.push(num);
        let mut count = 2;
        while temp[count - 2] - temp[count - 1] >= 0 {
            temp.push(temp[count - 2] - temp[count - 1]);
            count += 1;
        }
        if count > max_count {
            max_count = count;
            nums = temp;
        }
    }
    println!("{max_count}");
    nums.iter().for_each(|num| print!("{num} "));
}