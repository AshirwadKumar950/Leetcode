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
    vector<int>ans;
    void rec(TreeNode* root, int level){
        if(root == NULL) return;

        if(level >= ans.size()) ans.resize(level + 1,101);
        rec(root->right,level+1);
        rec(root->left,level+1);
        if(ans[level] == 101)
        ans[level] = root->val;
    }
    vector<int> rightSideView(TreeNode* root) {
        rec(root,0);
        return ans;
    }
};