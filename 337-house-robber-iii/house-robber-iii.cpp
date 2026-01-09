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
    unordered_map<TreeNode*,int>mp;
    int rec(TreeNode* root){
        if(!root) return 0;

        if(mp.count(root)) return mp[root];
        int nottake = rec(root->left) + rec(root->right);

        int take = root->val;
        if(root->left){
            take += rec(root->left->left);
            take += rec(root->left->right);
        }
        if(root->right){
            take += rec(root->right->left);
            take += rec(root->right->right);
        }
        return mp[root] = max(take,nottake);
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};