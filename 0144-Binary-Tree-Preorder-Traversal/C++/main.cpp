/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-26 14:58:30
 * @update on: 2019-03-26 19:28:47
 */
#include <iostream>
#include <vector>

using namespace std;

// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {  
        vector<int> record;
        preorderTraversal(root, record);
        return record;
    }
    void preorderTraversal(TreeNode* root, vector<int>& record) {
        if (root == NULL)
            return ;
        
        record.push_back(root->val);
        preorderTraversal(root->left, record);
        preorderTraversal(root->right, record);
    }
};

int main(int argc, char const *argv[]) {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = (Solution()).preorderTraversal(root);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
