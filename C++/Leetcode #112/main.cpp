#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::max
#include <optional>     // std::optional
#include <cstddef>      // std::size_t

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // check if node empty
        if(!root) return false;
        // check if leaf
        if(!root->left && !root->right) {
            // if leaf, check if sum matches
            if(targetSum-root->val == 0) return true;
            return false;
        } else {
            // if not leaf, check if sum-val matches children
            bool left = hasPathSum(root->left, targetSum - root->val);
            bool right = hasPathSum(root->right, targetSum - root->val);
            if (left || right) return true;
            return false;
        }
    }
};

TreeNode* constructTree(const std::vector<std::optional<int>>& vec, std::size_t index) {
    if (index >= vec.size() || !vec[index].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*vec[index]);
    root->left = constructTree(vec, 2 * index + 1);
    root->right = constructTree(vec, 2 * index + 2);
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
    std::vector<std::optional<int>> Vec = {5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt, std::nullopt, 1};
    int targetSum = 22;
    bool expected = true;

    TreeNode* root = constructTree(Vec, 0);

    Solution solution;
	bool output = solution.hasPathSum(root, targetSum);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<std::optional<int>> Vec = {1, 2, 3};
    int targetSum = 5;
    bool expected = false;

    TreeNode* root = constructTree(Vec, 0);

    Solution solution;
	bool output = solution.hasPathSum(root, targetSum);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<std::optional<int>> Vec = {};
    int targetSum = 0;
    bool expected = false;

    TreeNode* root = constructTree(Vec, 0);

    Solution solution;
	bool output = solution.hasPathSum(root, targetSum);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}
