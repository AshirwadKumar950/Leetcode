class Solution {
public:
    int rec(int n){
        if(n == 0 || n == 1) return 1;

        int total = 0;
        for(int i = 1; i <= n; i++){
            int left = rec(i-1);
            int right = rec(n - i);

            total += left*right;
        }
        return total;
    }
    int numTrees(int n) {
        //from 1 to n every eleent would be a root
        //and the unused element 
        //i will have to keep it in left and right 
        //side of it such that it forms a BST
        //to form a BST the rule is the right subtree must have 
        //all values higher than the root
        //and the left subtree all values smaller than the root
        return rec(n);
    }
};