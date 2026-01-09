/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    pair<bool,bool> rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return {false,false};

        pair<int,int> left = rec(root->left,p,q);
        pair<int,int> right = rec(root->right,p,q);

        bool foundp = left.first || right.first || root == p;
        bool foundq = left.second || right.second || root == q;


        if(foundp && foundq && ans == NULL){
            ans = root;
        }
        return {foundp,foundq};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        rec(root,p,q);
        return ans;
    }
};