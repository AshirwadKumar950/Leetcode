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
    vector<int>arr;
    void ino(TreeNode* root){
        if(root==NULL) return;
        ino(root->left);
        arr.push_back(root->val);
        ino(root->right);
    }
    TreeNode* make(int i, int j){
        if(i > j) return NULL;
        int mid = (i+j)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = make(i,mid-1);
        node->right = make(mid+1,j);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        ino(root);
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        return make(0,(int)arr.size()-1);
    }
};