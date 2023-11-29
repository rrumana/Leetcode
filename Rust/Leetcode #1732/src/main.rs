pub fn largest_altitude(gain: Vec<i32>) -> i32 {
    let mut max: i32 = 0;
    let mut current: i32 = 0;
    for x in gain.iter() {
        current += *x;
        if current > max {
            max = current;
        }
    }
    return max
}


#[cfg(test)]
mod tests {
    use crate::largest_altitude;

    #[test]
    fn test_one() {
        let gain = vec![-5,1,5,0,-7];
        assert_eq!(largest_altitude(gain), 1);
    }

    #[test]
    fn test_two() {
        let gain = vec![-4,-3,-2,-1,4,3,2];
        assert_eq!(largest_altitude(gain), 0);
    }
}

fn main() {
    println!("This function is useless!");
}