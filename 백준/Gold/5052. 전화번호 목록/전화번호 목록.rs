use std::{
    collections::HashMap,
    io::{self, stdin},
};

struct Trie {
    root: Node,
}

impl Trie {
    fn new() -> Self {
        Trie { root: Node::new() }
    }
}

impl Trie {
    fn insert(&mut self, s: &str) -> bool {
        let mut cur = &mut self.root;

        for c in s.chars() {
            if cur.is_end_of_word {
                return false;
            }
            cur = cur.nodes.entry(c).or_insert_with(Node::new);
        }

        if !cur.nodes.is_empty() {
            return false;
        }

        cur.is_end_of_word = true;

        true
    }
}

struct Node {
    nodes: HashMap<char, Node>,
    is_end_of_word: bool,
}

impl Node {
    fn new() -> Self {
        Node {
            nodes: HashMap::new(),
            is_end_of_word: false,
        }
    }
}

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let t = f().parse::<usize>().unwrap();
    let mut output = String::new();
    for _ in 0..t {
        let mut trie = Trie::new();
        let n = f().parse::<usize>().unwrap();
        let mut phones: Vec<&str> = (0..n).map(|_| f()).collect();

        phones.sort_unstable();

        let mut is_consistent = true;
        for phone in phones {
            if !trie.insert(phone) {
                is_consistent = false;
                break;
            }
        }

        if is_consistent {
            output.push_str("YES\n");
        } else {
            output.push_str("NO\n");
        }
    }

    print!("{output}");
}