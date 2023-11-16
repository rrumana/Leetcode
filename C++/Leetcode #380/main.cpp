#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

class RandomizedSet {
    private:
        std::vector<int> nums;
        std::unordered_map<int,int> map;

    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            if (map.find(val) != map.end()) {
                return false;
            } else {
                nums.emplace_back(val);
                map[val] = nums.size() -1;
                return true; 
            }
        }
        
        bool remove(int val) {
            if (map.find(val) == map.end()){
                return false;
            } else {
                int last = nums.back();
                map[last] = map[val];
                nums[map[val]] = last; 
                nums.pop_back();
                map.erase(val);
                return true;
            }
        }
        
        int getRandom() {
            return nums[rand() % nums.size()];
        }
};

void test1() {

}

void test2() {

}

void test3() {
    std::string s = "MCMXCIV";
    int output = 0;
    int expected = 1994;

    RandomizedSet solution;
	//output = solution.romanToInt (s);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    //test1();
    //test2();
    //test3();
	return 0;
}