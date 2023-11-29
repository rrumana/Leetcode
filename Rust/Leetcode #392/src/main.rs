pub fn is_subsequence(s: String, t: String) -> bool {
    let mut ptr_1 = 0;
    let mut ptr_2 = 0;
    let s_chars: Vec<char> = s.chars().collect();
    let t_chars: Vec<char> = t.chars().collect();

    while ptr_1 < s.len() && ptr_2 < t.len() {
        if s_chars[ptr_1] == t_chars[ptr_2] {
            ptr_1 += 1;
        }
        ptr_2 += 1;
    }
    ptr_1 == s.len()
}

#[cfg(test)]
mod tests {
    use crate::is_subsequence;

    #[test]
    fn test_one() {
        let s = String::from("abc");
        let t = String::from("ahbgdc");

        assert_eq!(gcd_of_strings(s, t), true);
    }

    #[test]
    fn test_two() {
        let s = String::from("axc");
        let t = String::from("ahbgdc");

        assert_eq!(gcd_of_strings(s, t), false);
    }

}

fn main() {
    println!("This function is useless!");
}