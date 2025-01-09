use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, a, b, c) = (f(), f(), f(), f());
    let mut toppings = (0..n).map(|_| f()).collect::<Vec<_>>();
    toppings.sort_unstable_by(|a, b| b.cmp(a));
    let (mut total_price, mut total_calories, mut calories_per_prices) = (a, c, c / a);
    for &topping in toppings.iter() {
        total_price += b;
        total_calories += topping;
        if calories_per_prices > total_calories / total_price {
            break;
        }
        calories_per_prices = total_calories / total_price;
    }
    print!("{calories_per_prices}");
}