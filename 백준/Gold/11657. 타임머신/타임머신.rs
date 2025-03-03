use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f() as usize, f() as usize);
    let vertices: Vec<(usize, usize, i64)> = (0..m)
        .map(|_| (f() as usize - 1, f() as usize - 1, f()))
        .collect();

    let dist = bellman_ford(n, &vertices);
    if dist[0] == i64::MIN {
        print!("-1");
    } else {
        print!(
            "{}",
            dist.iter()
                .skip(1)
                .map(i64::to_string)
                .collect::<Vec<_>>()
                .join("\n")
        );
    }
}

fn bellman_ford(nodes: usize, vertices: &[(usize, usize, i64)]) -> Vec<i64> {
    let mut dist = vec![i64::MAX; nodes];
    dist[0] = 0;
    for _ in 0..nodes - 1 {
        for (from, to, cost) in vertices {
            if dist[*from] < i64::MAX {
                dist[*to] = dist[*to].min(dist[*from] + *cost);
            }
        }
    }

    for (from, to, cost) in vertices {
        if dist[*from] < i64::MAX && dist[*to] > dist[*from] + *cost {
            dist[0] = i64::MIN;
            return dist;
        }
    }

    for i in 0..nodes {
        if dist[i] == i64::MAX {
            dist[i] = -1;
        }
    }

    dist
}