#include <iostream>         // std::cout
#include <vector>           // std::vector

/**
 * Definition for singly-linked list.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root == nullptr) return root;
      if(key < root->val) root->left = deleteNode(root->left, key);
      else if(key > root->val) root->right = deleteNode(root->right, key);
      else {
        if(root->left == nullptr) return root->right; // one child case
        else if(root->right == nullptr) return root->left; // one child case
        TreeNode* temp = root->right; // to find min from right subtree
        while(temp->left != nullptr) temp = temp->left; // temp has min
        root->val = temp->val; // change root to min
        root->right = deleteNode(root->right, temp->val); // delete old min
      }
      return root;   
    }
};

TreeNode* newNode(int value) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->val = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeNode* newNode(int value, TreeNode* left, TreeNode* right) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->val = value;
  node->left = left;
  node->right = right;
  return node;
}


TreeNode* constructTree(std::vector<int> vec, int index, int size) {
  TreeNode *root = nullptr;

  if (index < size) {
    if(vec[index] == -1) return nullptr;
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

bool areIdentical(struct TreeNode *a, struct TreeNode *b) {
  if (a == NULL && b == NULL) return true;
  if (a == NULL || b == NULL) return false;

  return (a->val == b->val && areIdentical(a->left, b->left) && areIdentical(a->right, b->right));
}

void test1() {
  std::vector<int> InputTree = {5,3,6,2,4,-1,7};
  std::vector<int> OutputTree = {5,4,6,2,-1,-1,7};

  int key = 3;

  TreeNode *input = constructTree(InputTree, 0, InputTree.size());
  TreeNode *expected = constructTree(OutputTree, 0, OutputTree.size());

  Solution solution;
  TreeNode *output = solution.deleteNode(input, key);

  //displayAll(input);
  //displayAll(expected);
  //displayAll(output);

  if(areIdentical(output, expected)) std::cout<<"Passed test 1"<<std::endl;
  else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::vector<int> InputTree = {5,3,6,2,4,-1,7};
  std::vector<int> OutputTree = {5,3,6,2,4,-1,7};

  int key = 0;

  TreeNode *input = constructTree(InputTree, 0, InputTree.size());
  TreeNode *expected = constructTree(OutputTree, 0, OutputTree.size());

  Solution solution;
  TreeNode *output = solution.deleteNode(input, key);

  //displayAll(input);
  //displayAll(expected);
  //displayAll(output);

  if(areIdentical(output, expected)) std::cout<<"Passed test 2"<<std::endl;
  else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
  std::vector<int> InputTree = {};
  std::vector<int> OutputTree = {};

  int key = 0;

  TreeNode *input = constructTree(InputTree, 0, InputTree.size());
  TreeNode *expected = constructTree(OutputTree, 0, OutputTree.size());

  Solution solution;
  TreeNode *output = solution.deleteNode(input, key);

  //displayAll(input);
  //displayAll(expected);
  //displayAll(output);

  if(areIdentical(output, expected)) std::cout<<"Passed test 3"<<std::endl;
  else std::cout<<"Failed test 3"<<std::endl;

}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
