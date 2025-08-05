fn search(k: i32, subset: &mut Vec<i32>, n: i32) {
    if k == n + 1 {
        // print subset
        for s in subset {
            print!("{s} ");
        }
        println!();
    } else {
        subset.push(k);
        search(k + 1, subset, n);
        subset.pop();
        search(k + 1, subset, n);
    }
}

fn main() {
    let mut subset: Vec<i32> = Vec::<i32>::new();

    search(1, &mut subset, 3);

    println!("Hello, world!");
}
