use std::collections::HashMap;
use std::collections::HashSet;

pub fn unique_occurrences(arr: Vec<i32>) -> bool {
    let mut map = HashMap::new();
    let mut set = HashSet::new();
    for i in arr {
        let count = map.entry(i).or_insert(0);
        *count += 1;
    }
    for (_, value) in map {
        if !set.insert(value) {
            return false;
        }
    }
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_one() {
        let input_array = vec![1, 2, 2, 1, 1, 3];
        assert_eq!(unique_occurrences(input_array), true);
    }

    #[test]
    fn test_two() {
        let input_array = vec![1, 2];
        assert_eq!(unique_occurrences(input_array), false);
    }
    
    #[test]
    fn test_three() {
        let input_array = vec![-3,0,1,-3,1,1,1,-3,10,0];
        assert_eq!(unique_occurrences(input_array), true);
    }
}

fn main() {
    println!("This function is useless!");
}
