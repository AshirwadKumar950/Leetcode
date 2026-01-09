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
    void dfs(TreeNode* root, int val, int depth, int curr){
        if(!root) return;

        if(curr == depth-1){
            TreeNode* node = new TreeNode(val);
            TreeNode* t = root->left;
            root->left = node;
            node->left = t;
            TreeNode* node1 = new TreeNode(val);
            TreeNode* t1 = root->right;
            root->right = node1;
            node1->right = t1;
            return;
        }
        dfs(root->left,val,depth,curr+1);
        dfs(root->right,val,depth,curr+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root,val,depth,1);
        return root;
    }
};