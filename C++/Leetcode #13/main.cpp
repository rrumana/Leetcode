#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int total = 0;
        
        for(int i = 0; i < s.size(); i++){
            int current = map[s[i]];
            int next = map[s[i+1]];

            if(current >= next){
                total += current;
            } else {
                total -= current;
            }
        }
        return total;
    }
};

void test1() {
    std::string s = "III";
    int output = 0;
    int expected = 3;

    Solution solution;
	output = solution.romanToInt (s);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::string s = "LVIII";
    int output = 0;
    int expected = 58;

    Solution solution;
	output = solution.romanToInt (s);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::string s = "MCMXCIV";
    int output = 0;
    int expected = 1994;

    Solution solution;
	output = solution.romanToInt (s);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}