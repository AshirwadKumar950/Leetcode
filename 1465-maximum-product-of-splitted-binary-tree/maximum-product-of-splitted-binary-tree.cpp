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
    typedef long long ll;
    const int MOD = 1e9+7;
    ll totalSum = 0;
    ll ans = 0;
    ll sum = 0;
    void inorder(TreeNode* root){
        if(!root) return;

        totalSum += root->val;
        inorder(root->left);
        inorder(root->right);
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        
        ll left = dfs(root->left);
        ll right = dfs(root->right);

        ll subtree = left + right + root->val;
        ans = (max(1ll*ans,(1ll*(totalSum-subtree)*subtree)));
        return subtree;
    }

    int maxProduct(TreeNode* root) {
        inorder(root);
        dfs(root);
        return ans%MOD;
    }
};