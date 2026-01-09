/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int>rec(TreeNode* root){
        if(!root) return {0,0};

        auto left = rec(root->left);
        auto right = rec(root->right);

        int rob =  root->val + left.second + right.second;
        int dontrob = max(left.first,left.second) + max(right.first,right.second);
        return {rob,dontrob};
    }
    int rob(TreeNode* root) {
        auto v =  rec(root);
        return max(v.first,v.second);
    }
};