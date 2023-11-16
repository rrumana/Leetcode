#include <iostream>
#include <iterator>
#include <unordered_set>
#include <random>

class RandomizedSet {
public:

    std::unordered_set<int> set;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (set.find(val) == set.end()){
            set.insert(val);
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (set.find(val) != set.end()){
            set.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        srand (time(NULL));
        int random = rand() % set.size();
        set.insert(random);
        std::unordered_set<int>::iterator itr = set.find(random);
        if(itr == set.end()){
            itr = set.begin();
        } else {
            itr++;
        }
        set.erase(random);
        return *itr;
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