/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-26 14:58:30
 * @update on: 2019-03-26 19:31:41
 */
#include <iostream>
#include <vector>

using namespace std;

// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {  
        vector<int> record;
        inorderTraversal(root, record);
        return record;
    }
    void inorderTraversal(TreeNode* root, vector<int>& record) {
        if (root == NULL)
            return ;
        
        inorderTraversal(root->left, record);
        record.push_back(root->val);
        inorderTraversal(root->right, record);
    }
};

int main(int argc, char const *argv[]) {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = (Solution()).inorderTraversal(root);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
