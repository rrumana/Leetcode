pub fn gcd_of_strings(str1: String, str2: String) -> String {
    if &(str1.clone() + &str2) != &(str2.clone() + &str1) {
        return "".to_string();
    }
    let length = gcd(str1.len(), str2.len());
    str1[0..length].to_owned()
}


pub fn gcd(n1: usize, n2: usize) -> usize{
    if n2 == 0 {
        return n1;
    }
    gcd(n2, n1 % n2)
}


#[cfg(test)]
mod tests {
    use crate::gcd_of_strings;

    #[test]
    fn test_one() {
        let str1 = String::from("ABCABC");
        let str2 = String::from("ABC");

        assert_eq!(gcd_of_strings(str1, str2), String::from("ABC"));
    }

    #[test]
    fn test_two() {
        let str1 = String::from("ABABAB");
        let str2 = String::from("AB");

        assert_eq!(gcd_of_strings(str1, str2), String::from("AB"));
    }

    #[test]
    fn test_three() {
        let str1 = String::from("LEET");
        let str2 = String::from("CODE");

        assert_eq!(gcd_of_strings(str1, str2), String::from(""));
    }

    #[test]
    fn test_four() {
        let str1 = String::from("AB");
        let str2 = String::from("AB");

        assert_eq!(gcd_of_strings(str1, str2), String::from("AB"));
    }
}

fn main() {
    println!("This function is useless!");
}