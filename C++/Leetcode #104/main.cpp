#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::max

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return std::max(maxLeft, maxRight)+1;
    }
};

TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

TreeNode* constructTree(std::vector<int> vec, int index, int size) {
    TreeNode *root = nullptr;

    if (index < size && vec[index] != 0) {
        root = newNode(vec[index]);
         
        root->left = constructTree(vec, 2 * index + 1, size);
        root->right = constructTree(vec, 2 * index + 2, size);
    }
    return root;
}

void displayAll(TreeNode* root) {
	if(root) {
		std::cout<<root->val<<" ";
		displayAll(root->left);	
		displayAll(root->right);		
	}
}

void test1() {
    std::vector<int> Vec = {3,9,20,NULL,NULL,15,7};
    int expected = 3;

    TreeNode* root1 = constructTree(Vec, 0, Vec.size());

    Solution solution;
	int output = solution.maxDepth(root1);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> Vec = {1,NULL,2};
    int expected = 2;

    TreeNode* root1 = constructTree(Vec, 0, Vec.size());

    Solution solution;
	int output = solution.maxDepth(root1);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {}

int main() {
    test1();
    test2();
	return 0;
}