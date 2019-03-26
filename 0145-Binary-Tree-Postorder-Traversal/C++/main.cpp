/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-26 14:58:30
 * @update on: 2019-03-26 19:34:19
 */
#include <iostream>
#include <vector>

using namespace std;

// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {  
        vector<int> record;
        postorderTraversal(root, record);
        return record;
    }
    void postorderTraversal(TreeNode* root, vector<int>& record) {
        if (root == NULL)
            return ;
        
        postorderTraversal(root->left, record);
        postorderTraversal(root->right, record);
        record.push_back(root->val);
    }
};

int main(int argc, char const *argv[]) {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = (Solution()).postorderTraversal(root);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
