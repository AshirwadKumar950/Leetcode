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
    int ways = 0;
    void rec(TreeNode* root, ll t, ll curr){
        if(!root) return;

        curr += root->val;
        ll req = curr-t;
        if(mp.find(req) != mp.end()){
            ways += mp[req];
        }
        mp[curr]++;
        rec(root->left,t,curr);
        rec(root->right,t,curr);
        mp[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        rec(root,1ll*targetSum,1ll*0);
        return ways;
    }
};