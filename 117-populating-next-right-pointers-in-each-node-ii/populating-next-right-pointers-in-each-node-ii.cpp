/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>queue;
        queue.push(root);
        while(!queue.empty()){
            int sz = queue.size();
            Node* last = NULL;
            while(sz--){
                Node* current = queue.front();
                queue.pop();

                if(sz == 0){
                    current->next = NULL;
                }else{
                    Node* next = queue.front();
                    current->next = next;
                }
                if(current->left) queue.push(current->left);
                if(current->right) queue.push(current->right);
            }
        }
        return root;
    }
};