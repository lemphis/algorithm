use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut switches = input.by_ref().take(n).collect::<Vec<_>>();
    let student_count = input.next().unwrap();
    for _ in 0..student_count {
        let (gender, num) = (input.next().unwrap(), input.next().unwrap() - 1);
        if gender == 1 {
            for i in (num..n).step_by(num + 1) {
                switches[i] ^= 1;
            }
        } else {
            switches[num] ^= 1;
            let mut d = 1;
            while num as i32 - d >= 0
                && num as i32 + d < n as i32
                && switches[num - d as usize] == switches[num + d as usize]
            {
                switches[num - d as usize] ^= 1;
                switches[num + d as usize] ^= 1;
                d += 1;
            }
        }
    }
    print!(
        "{}",
        switches
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .chunks(20)
            .map(|chunk| chunk.join(" "))
            .collect::<Vec<_>>()
            .join("\n")
    );
}