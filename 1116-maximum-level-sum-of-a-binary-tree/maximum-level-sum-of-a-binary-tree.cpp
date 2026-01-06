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
    vector<int>allLevelSum;
    void dfs(TreeNode* root, int level){
        if(root == NULL) return;

        if(level >= allLevelSum.size()){
            allLevelSum.resize(level+1,0);
        }

        allLevelSum[level] += root->val;
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int answerLevel = INT_MAX;
        int maximumSum = INT_MIN;
        int sz = allLevelSum.size();
        for(int i = 1; i < sz; i++){
            if(allLevelSum[i] > maximumSum){
                maximumSum = allLevelSum[i];
                answerLevel = i;
            }
        }
        return answerLevel;
    }
};