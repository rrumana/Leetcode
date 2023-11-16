#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        int size = prices.size();

        if(size == 1) return 0;

        for(int i = 1; i < size; i++){
            if(prices[i-1] < prices[i])
                profit+=(prices[i] - prices[i-1]);

        }

        return profit;
    }
};

void test1() {
    std::vector<int> input = {7,1,5,3,6,4};
    int output = 0;
    int expected = 7;

    Solution solution;
	output = solution.maxProfit (input);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> input = {1,2,3,4,5};
    int output = 0;
    int expected = 4;

    Solution solution;
	output = solution.maxProfit (input);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> input = {7,6,4,3,1};
    int output = 0;
    int expected = 0;

    Solution solution;
	output = solution.maxProfit (input);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

void test4() {
    std::vector<int> input = {1,5,1,6,3,1};
    int output = 0;
    int expected = 9;

    Solution solution;
	output = solution.maxProfit (input);

    if(output == expected) std::cout<<"Passed test 4"<<std::endl;
	else std::cout<<"Failed test 4"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
	return 0;
}
