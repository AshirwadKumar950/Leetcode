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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll>levelSum;
        queue<TreeNode*>queue;
        queue.push(root);

        while(!queue.empty()){
            int sz = queue.size();
            ll currSum = 0;
            while(sz--){
                TreeNode* currNode = queue.front();
                queue.pop();

                currSum += currNode->val;

                if(currNode->left != NULL) queue.push(currNode->left);
                if(currNode->right != NULL) queue.push(currNode->right);
            }
            levelSum.push_back(currSum);
        }
        if(levelSum.size() < k) return -1;
        sort(levelSum.rbegin(),levelSum.rend());
        return levelSum[k-1];
    }
};