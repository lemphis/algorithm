use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let mut credit_count = 0.0;
    let mut total_credit = 0.0;
    for _ in 0..20 {
        let _ = input.next().unwrap();
        let credit = input.next().unwrap().parse::<f64>().unwrap();
        let grade = input.next().unwrap();
        let score = match grade {
            "A+" => 4.5,
            "A0" => 4.0,
            "B+" => 3.5,
            "B0" => 3.0,
            "C+" => 2.5,
            "C0" => 2.0,
            "D+" => 1.5,
            "D0" => 1.0,
            "P" => 0.0,
            "F" => 0.0,
            _ => 0.0,
        };
        if grade != "P" {
            credit_count += credit;
        }
        total_credit += credit * score;
    }
    println!("{}", format!("{:.6}", total_credit / credit_count));
}
