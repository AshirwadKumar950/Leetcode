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
    int ans;
    int maxi = INT_MIN;
    void rec(TreeNode* root, int depth){
        if(!root) return ;
        if(depth > maxi){
            maxi = depth;
            ans = root->val;
        }
        rec(root->left,depth+1);
        rec(root->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        //go to deepest left node
        rec(root,0);
        return ans;
    }
};