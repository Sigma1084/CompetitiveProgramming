use std::io;

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn main() {
    // Read a line of input from the user
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let n: i32 = input.trim().parse().expect("Invalid input");

	if n == 2 || n == 4 {
		println!("1\n1\n");
		return;
	}

	let mut vec: Vec<i32> = Vec::new();
	for i in 1..n {
		if gcd(i, n) == 1 {
			vec.push(i);
		}
	}

	if vec.len() + 1 == n as usize {
		vec.pop();
	}

	println!("{}", vec.len());
	for i in 0..vec.len() {
		print!("{} ", vec[i]);
	}

	let product_mod: i32 = vec.iter().fold(1, |acc, &x| acc * (x as i64) % (n as i64)) as i32;
	assert_eq!(product_mod, 1);
}
