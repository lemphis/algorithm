use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut dairies = input.skip(1).collect::<Vec<_>>();
    dairies.sort_unstable_by(|a, b| b.cmp(a));
    print!(
        "{}",
        dairies.iter().sum::<usize>()
            - dairies
                .iter()
                .enumerate()
                .filter_map(|(i, diary)| if i % 3 == 2 { Some(diary) } else { None })
                .sum::<usize>()
    );
}