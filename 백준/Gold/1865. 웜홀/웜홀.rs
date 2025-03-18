use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let tc = f();
    let mut output = String::with_capacity(1 << 10);
    for _ in 0..tc {
        let (n, m, w) = (f(), f(), f());
        let mut edges = Vec::with_capacity(m * 2 + w);
        for _ in 0..m {
            let (s, e, t) = (f() - 1, f() - 1, f() as i32);
            edges.push((s, e, t));
            edges.push((e, s, t));
        }
        for _ in 0..w {
            let (s, e, t) = (f() - 1, f() - 1, f() as i32);
            edges.push((s, e, -t));
        }

        output.push_str(&format!(
            "{}\n",
            if has_negative_cycle(&edges, n) {
                "YES"
            } else {
                "NO"
            }
        ));
    }

    print!("{output}");
}

fn has_negative_cycle(edges: &[(usize, usize, i32)], n: usize) -> bool {
    let mut dist = vec![0; n + 1];

    for _ in 0..n - 1 {
        for &(s, e, w) in edges.iter() {
            if dist[s] < i32::MAX {
                dist[e] = dist[e].min(dist[s] + w);
            }
        }
    }

    for &(s, e, w) in edges.iter() {
        if dist[e] > dist[s] + w {
            return true;
        }
    }

    false
}