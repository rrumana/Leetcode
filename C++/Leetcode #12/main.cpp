#include <iostream>
#include <string>

class Solution {
public:
    std::string romanToInt(int num) {
        std::string ans = "";
        
        while(num > 0) {
            if(num >= 1000){
                num = num - 1000;
                ans += 'M';
            } else if(num >= 900){
                num = num - 900;
                ans += "C";
                ans += "M";
            } else if(num >= 500){
                num = num - 500;
                ans += 'D';
            } else if(num >= 400){
                num = num - 400;
                ans += 'C';
                ans += 'D';
            } else if(num >= 100){
                num = num - 100;
                ans += 'C';
            } else if(num >= 90){
                num = num - 90;
                ans += 'X';
                ans += 'C';
            } else if(num >= 50){
                num = num - 50;
                ans += 'L';
            } else if(num >= 40){
                num = num - 40;
                ans += 'X';
                ans += 'L';
            } else if(num >= 10){
                num = num - 10;
                ans += 'X';
            } else if(num >= 9){
                num = num - 9;
                ans += 'I';
                ans += 'X';
            } else if(num >= 5){
                num = num - 5;
                ans += 'V';
            } else if(num >= 4){
                num = num - 4;
                ans += 'I';
                ans += 'V';
            } else if(num >= 1){
                num = num - 1;
                ans += 'I';
            }
        }
        return ans;
    }
};

void test1() {
    int num = 3;
    std::string output = "";
    std::string expected = "III";

    Solution solution;
	output = solution.romanToInt (num);

    //std::cout << output << std::endl;

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    int num = 58;
    std::string output = "";
    std::string expected = "LVIII";

    Solution solution;
	output = solution.romanToInt (num);

    //std::cout << output << std::endl;

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    int num = 1994;
    std::string output = "";
    std::string expected = "MCMXCIV";

    Solution solution;
	output = solution.romanToInt (num);

    //std::cout << output << std::endl;

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}