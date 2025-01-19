use std::{
    collections::HashMap,
    io::{self, stdin},
};

struct Book {
    price: usize,
    name: String,
}

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (t, n) = (f(), f().parse::<usize>().unwrap());
    let books = (0..n)
        .map(|_| {
            let price = f().parse::<usize>().unwrap();
            let name = f().to_string();
            Book { price, name }
        })
        .collect::<Vec<_>>();
    let mut min_price = usize::MAX;
    let (mut target, mut compare) = (HashMap::new(), HashMap::new());
    for c in t.chars() {
        *target.entry(c).or_insert(0) += 1;
        compare.insert(c, 0);
    }
    dfs(&books, &target, &mut compare, 0, 0, &mut min_price);
    if min_price == usize::MAX {
        print!("-1");
    } else {
        print!("{min_price}");
    }
}

fn dfs(
    books: &[Book],
    target: &HashMap<char, usize>,
    compare: &mut HashMap<char, usize>,
    start: usize,
    total_price: usize,
    min_price: &mut usize,
) {
    if start == books.len() {
        return;
    }
    for i in start..books.len() {
        for c in books[i].name.chars() {
            if let Some(count) = compare.get_mut(&c) {
                *count += 1;
            }
        }
        if compare.iter().all(|(k, v)| target.get(k).unwrap() <= v) {
            *min_price = (*min_price).min(total_price + books[i].price);
        } else {
            dfs(
                books,
                target,
                compare,
                i + 1,
                total_price + books[i].price,
                min_price,
            );
        }
        for c in books[i].name.chars() {
            if let Some(count) = compare.get_mut(&c) {
                *count -= 1;
            }
        }
    }
}