use std::collections::HashSet;

pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
    let hash1: HashSet<i32> = nums1.iter().cloned().collect();
    let hash2: HashSet<i32> = nums2.iter().cloned().collect();

    let res_hash1: HashSet<i32> = hash1.difference(&hash2).cloned().collect();
    let res_hash2: HashSet<i32> = hash2.difference(&hash1).cloned().collect();

    return
        vec![
            res_hash1.into_iter().collect(), 
            res_hash2.into_iter().collect(),
        ];
}


#[cfg(test)]
mod tests {
    use crate::find_difference;

    #[test]
    fn test_one() {
        let nums1 = vec![1,2,3];
        let nums2 = vec![2,4,6];
        let expected = vec![vec![1,3],vec![4,6]];

        assert_eq!(find_difference(nums1, nums2), expected);
    }

    #[test]
    fn test_two() {
        let nums1 = vec![1,2,3,3];
        let nums2 = vec![1,1,2,2];
        let expected = vec![vec![3],vec![]];

        assert_eq!(find_difference(nums1, nums2), expected);
    }
}

fn main() {
    println!("This function is useless!");
}