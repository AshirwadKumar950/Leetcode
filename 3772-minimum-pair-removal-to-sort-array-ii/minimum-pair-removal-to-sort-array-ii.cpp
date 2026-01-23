class Solution {
public:
    typedef long long ll;
    struct List{
        ll val;
        List* prev;
        List* next;
        bool deleted;
        List(ll v) : val(v), prev(nullptr), next(nullptr), deleted(false) {}
    };
    
    typedef pair<ll,List*> pil;
    List* create(vector<int>& nums){
        List* root = NULL, *head = NULL;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            List* p = new List(1ll*nums[i]);
            if(root == NULL){
                root = head = p;
            }else{
                head->next = p;
                p->prev = head;
                head = p;
            }
        }
        return root;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1];
        /*
            in one map<int,int> i have got index and it's value
            and in another i got 
            mp2[i] = arr[i]+arr[i+1];

            [5,2,3,1,8,9,12,3,1,18]
            for this example 
            [7,5,4,9,17,21,15,4,19]
            i will remove 4th first so 
            updated elemnts wil be 
            [5,2,4,8,9,12,3,1,18]
            [7,6,12,17,21,15,4,19]

            iteration 3- 
            [5,2,4,8,9,12,4,18]
            [7,6,12,17,21,16,22]

            iteration 4-
            [5,6,8,9,12,4,18]
            [11,14,17,21,16,22]

            iteration 5 -
            [5,6,8,9,12,4,18]
            [11,14,17,21,16,22]

            iteration 6 -
            [11,8,9,12,4,18]
            [19,17,21,16,22]

            i think it's better to maintain a linkedlist ans use it efficiently to update vlaues 
            no need of indices
        */  

        List* root = create(nums);

        priority_queue<pil, vector<pil>, greater<pil>>pq;

        set<pair<List*,ll>>badPairs;
        List *t = root;
        int badCount = 0;
        //pushed in priority queue value and it's node address
        for(List* t = root; t->next != NULL; t = t->next){
            ll val = t->val + t->next->val;
            pq.push({val,t});
            if(t->val > t->next->val){
                badCount++;
            }
        }

        int count = 0;
        while(!pq.empty() && badCount > 0){
            auto [sumVal, node] = pq.top();
            pq.pop();
            //Skip if node or its neighbor was already merged
            if(node->deleted || !node->next || node->next->deleted) continue;
            if(node->val + node->next->val != sumVal) continue;

            //Before merging remove the bad contribution of affected pairs
            if(node->val > node->next->val) badCount--;
            if(node->prev && node->prev->val > node->val) badCount--;
            if(node->next->next && node->next->val > node->next->next->val) badCount--;

            //Perform the merge node + node->next
            List* toDelete = node->next;
            node->val = sumVal;
            node->next = toDelete->next;
            if(toDelete->next) toDelete->next->prev = node;
            toDelete->deleted = true; 

            //After merging add bad contribution of new adjacencies
            if(node->prev && node->prev->val > node->val) badCount++;
            if(node->next && node->val > node->next->val) badCount++;

            //Push new potential sums to PQ
            if(node->prev) pq.push({node->prev->val + node->val, node->prev});
            if(node->next) pq.push({node->val + node->next->val, node});
            count++;
        }
        return count;
    }
};