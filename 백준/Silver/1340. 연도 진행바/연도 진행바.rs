use std::io::{self, Read};

const DAYS: [u32; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
const MONTHS: [(&str, u32); 12] = [
    ("January", 1),
    ("February", 2),
    ("March", 3),
    ("April", 4),
    ("May", 5),
    ("June", 6),
    ("July", 7),
    ("August", 8),
    ("September", 9),
    ("October", 10),
    ("November", 11),
    ("December", 12),
];

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let month_str = input.next().unwrap();
    let mut month = 0;
    for (s, m) in MONTHS {
        if s == month_str {
            month = m;
            break;
        }
    }
    let day = input
        .next()
        .unwrap()
        .split(',')
        .next()
        .unwrap()
        .parse::<u32>()
        .unwrap();
    let year = input.next().unwrap().parse::<u32>().unwrap();
    let mut hm_str = input.next().unwrap().split(':');
    let hour = hm_str.next().unwrap().parse::<u32>().unwrap();
    let minute = hm_str.next().unwrap().parse::<u32>().unwrap();
    let is_leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    let mut days_total_cnt = if is_leap_year { 1 } else { 0 };
    for i in 0..MONTHS.len() {
        days_total_cnt += DAYS[i];
    }
    let year_total_seconds = 60 * 60 * 24 * days_total_cnt;

    let mut days_cnt = day - 1;
    for i in 0..month - 1 {
        days_cnt += DAYS[i as usize];
        if i == 1 && is_leap_year {
            dbg!("??");
            days_cnt += 1;
        }
    }
    let mut total_seconds = 60 * 60 * 24 * days_cnt + 60 * minute;
    if hour > 0 {
        total_seconds += 60 * 60 * hour;
    }
    print!(
        "{}",
        total_seconds as f64 / year_total_seconds as f64 * 100f64
    );
}