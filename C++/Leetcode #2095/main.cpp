#include <iostream>         // std::cout
#include <vector>           // std::vector

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int findMiddle(ListNode* head) {
        ListNode *current = head;
        int counter = 0;

        while(current != NULL){
            counter++;
            current = current->next;
        }
        return counter/2;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head->next;
        
        int middle = findMiddle(head);
        ListNode *current = head;

        for(int i = 1; i < middle; ++i){
            current = current->next;
        }

        current->next = current->next->next;
        return head;
    }
};

ListNode* newNode(int value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

ListNode* constructList(std::vector<int> vec, int index, int size) {
    ListNode *root = nullptr;

    if (index < size) {
        root = newNode(vec[index]);
         
        root->next = constructList(vec, index + 1, size);
    }
    return root;
}



void displayAll(ListNode* root) {
	if(root) {
		std::cout<<root->val<<" ";
		displayAll(root->next);		
	}
}

bool areIdentical(struct ListNode *a, struct ListNode *b) {
    while (a != NULL && b != NULL) {
        if (a->val != b->val)
            return false;

        a = a->next;
        b = b->next;
    }
 
    return (a == NULL && b == NULL);
}

void test1() {
    std::vector<int> Vec1 = {1,3,4,7,1,2,6};
    std::vector<int> Vec2 = {1,3,4,1,2,6};

    ListNode *input = constructList(Vec1, 0, Vec1.size());
    ListNode *expected = constructList(Vec2, 0, Vec2.size());

    Solution solution;
	ListNode *output = solution.deleteMiddle(input);

    //displayAll(output);

    if(areIdentical(output, expected)) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> Vec1 = {1,2,3,4};
    std::vector<int> Vec2 = {1,2,4};

    ListNode *input = constructList(Vec1, 0, Vec1.size());
    ListNode *expected = constructList(Vec2, 0, Vec2.size());

    Solution solution;
	ListNode *output = solution.deleteMiddle(input);

    //displayAll(output);

    if(areIdentical(output, expected)) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> Vec1 = {2,1};
    std::vector<int> Vec2 = {2};

    ListNode *input = constructList(Vec1, 0, Vec1.size());
    ListNode *expected = constructList(Vec2, 0, Vec2.size());

    Solution solution;
	ListNode *output = solution.deleteMiddle(input);

    //displayAll(output);

    if(areIdentical(output, expected)) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

void test4() {
    std::vector<int> Vec1 = {1};
    std::vector<int> Vec2 = {};

    ListNode *input = constructList(Vec1, 0, Vec1.size());
    ListNode *expected = constructList(Vec2, 0, Vec2.size());

    Solution solution;
	ListNode *output = solution.deleteMiddle(input);

    displayAll(output);

    if(areIdentical(output, expected)) std::cout<<"Passed test 4"<<std::endl;
	else std::cout<<"Failed test 4"<<std::endl;
}

void test5() {
    std::vector<int> Vec1 = {};
    std::vector<int> Vec2 = {};

    ListNode *input = constructList(Vec1, 0, Vec1.size());
    ListNode *expected = constructList(Vec2, 0, Vec2.size());

    Solution solution;
	ListNode *output = solution.deleteMiddle(input);

    displayAll(output);

    if(areIdentical(output, expected)) std::cout<<"Passed test 5"<<std::endl;
	else std::cout<<"Failed test 5"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
	return 0;
}