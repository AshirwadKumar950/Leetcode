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
    int ways = 0;
    void rec(TreeNode* root, int t){
        if(!root) return;
        if(root->val > 1e8-1) return;
        if(root->val == t) ways++;

        rec(root->left,t-root->val);
        rec(root->right,t-root->val);
    }
    void dfs(TreeNode* root, int t){
        if(!root) return;

        rec(root,t);
        dfs(root->left,t);
        dfs(root->right,t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ways;
    }
};