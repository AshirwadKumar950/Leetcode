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
    unordered_map<ll,int>mp;
    ll rec(TreeNode* root){
        if(!root) return 0;

        ll left = rec(root->left);
        ll right = rec(root->right);

        ll currsum = root->val + left + right;
        mp[currsum]++;
        return currsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        rec(root);

        vector<int>ans;
        int most = 0;
        for(auto &[k,f] : mp){
            if(f > most){
                ans.clear();
                most = f;
                ans.push_back(k);
            }else if(f == most){
                ans.push_back(k);
            }
        }
        return ans;
    }
};