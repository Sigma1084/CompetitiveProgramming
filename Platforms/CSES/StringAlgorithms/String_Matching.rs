use std::io::{BufWriter, stdin, stdout};
use std::vec::Vec;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn zFunc(s: &str) -> Vec<usize> {
    let n: usize = s.len();
    let mut z: Vec<usize> = vec![0; n];
    let (mut l, mut r) = (0, 0);
    for i in 1..n {
        if i <= r {
            z[i] = std::cmp::min(r - i + 1, z[i - l]);
        }
        while i + z[i] < n && s.chars().nth(z[i]).unwrap() == s.chars().nth(i + z[i]).unwrap() {
            z[i] += 1;
        }
        if i + z[i] - 1 > r {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let s = scan.next::<String>();
    let p = scan.next::<String>();

    let z = zFunc(&format!("{}${}", p, s));
    let mut ans: usize = 0;
    for i in p.len() + 1..z.len() {
        if z[i] == p.len() {
            ans += 1;
        }
    }
    println!("{}", ans);
}
