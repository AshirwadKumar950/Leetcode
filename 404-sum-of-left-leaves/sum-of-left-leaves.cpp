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
    int sum = 0;
    void rec(TreeNode* root,TreeNode* parent){
        if(!root) return;

        if(root->left == NULL && root->right == NULL && parent !=NULL &&parent->left == root){
            sum += root->val;
        }
        rec(root->left,root);
        rec(root->right,root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
       rec(root,NULL);
       return sum;
    }
};