pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
    asteroids.into_iter()
        .fold(vec![], |mut v, x| {
            match x > 0 {
                true => v.push(x),
                false => {
                    while let Some(&y) = v.last() {
                        if y < 0 {break;}
                        if y < x.abs() {v.pop();}
                        else if y == x.abs() {v.pop(); return v;}
                        else {return v;}
                    };
                    if v.is_empty() || v.last() < Some(&0) {v.push(x);}
                },
            };
            v
        })
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_one() {
        let input_array = vec![5, 10, -5];
        let expected = vec![5,10];
        assert_eq!(asteroid_collision(input_array), expected);
    }

    #[test]
    fn test_two() {
        let input_array = vec![8, -8];
        let expected = vec![];
        assert_eq!(asteroid_collision(input_array), expected);
    }    

    #[test]
    fn test_three() {
        let input_array = vec![10,2,-5];
        let expected = vec![10];
        assert_eq!(asteroid_collision(input_array), expected);
    }

    #[test]
    fn test_four() {
        let input_array = vec![-2,-1,1,2];
        let expected = vec![-2,-1,1,2];
        assert_eq!(asteroid_collision(input_array), expected);
    }


    #[test]
    fn test_five() {
        let input_array = vec![1,-2,-2,-2];
        let expected = vec![-2,-2,-2];
        assert_eq!(asteroid_collision(input_array), expected);
    }

}

fn main() {
    println!("This function is useless!");
}
