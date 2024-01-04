#include <iostream>     // std::cout
#include <vector>       // std::vector


class Solution {
private:
    int number;
public:
    void setGuess(int value) {
        number = value;
    }
    int guess(int value) {
        if(value > number) return -1;
        else if (value < number) return 1;
        else return 0;
    }
    int guessNumber(int n) {
        long long lo = 1, hi = n, mid;

        while(lo <= hi) {
            mid = (lo+hi) >> 1;
            if(guess(mid) == 0) return mid;
            if(guess(mid) == -1) hi = mid - 1;
            else lo = mid + 1;
        }
        return mid;
    }
};

void test1() {
    int max = 10;
    int expected = 6;

    Solution solution;
    solution.setGuess(expected);
	int output = solution.guessNumber(max);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    int max = 1;
    int expected = 1;
        
    Solution solution;
    solution.setGuess(expected);
	int output = solution.guessNumber(max);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    int max = 2;
    int expected = 1;
        
    Solution solution;
    solution.setGuess(expected);
	int output = solution.guessNumber(max);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}