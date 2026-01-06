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
    int maxLevelSum(TreeNode* root) {
        int answerLevel = INT_MAX;
        int maximumSum = INT_MIN;
        queue<TreeNode*>queue;
        queue.push(root);
        int level = 1;
        while(!queue.empty()){
            int sz = queue.size();
            int thisLevelSum = 0;
            while(sz--){
                TreeNode* currentNode = queue.front();
                queue.pop();
                thisLevelSum += currentNode->val;

                if(currentNode->left != NULL) queue.push(currentNode->left);
                if(currentNode->right != NULL) queue.push(currentNode->right);
            }
            if(thisLevelSum > maximumSum){
                maximumSum = thisLevelSum;
                answerLevel = level;
            }
            level++;
        }
        return answerLevel;
    }
};