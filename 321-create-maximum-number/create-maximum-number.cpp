class Solution {
public:
    int check(vector<int>&v1, vector<int>&v2, int m , int n, int x, int y){
        while(x < m && y < n){
            if(v1[x] > v2[y]) return 1;
            else if(v2[y] > v1[x]) return 0;
            x++;
            y++;
        }
        if(x == m && y == n) return 1;
        if(x == m) return 0;
        return 1;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        //i have to make lexicographically largest number 
        //with it's order being maintained
        vector<int>result;
        for(int x = max(0,k-n); x <= min(k,m); x++){
            stack<int>st1,st2;
            //i have to take x elements from nums1 lexicographically largest
            for(int i = 0; i < m; i++){
                while(!st1.empty() && (m-i-1) >= x - st1.size() && st1.top() < nums1[i]){
                    st1.pop();
                }
                if(st1.size() < x)
                st1.push(nums1[i]);
            }
            for(int i = 0; i < n; i++){
                while(!st2.empty() && (n-i-1) >= (k-x) - st2.size() && st2.top() < nums2[i]){
                    st2.pop();
                }
                if(st2.size() < (k-x))
                st2.push(nums2[i]);
            }

            int sz1 = st1.size();
            int sz2 = st2.size();
            vector<int>v1(sz1),v2(sz2);
            for(int i = sz1-1; i >= 0; i--){
                v1[i] = st1.top();
                st1.pop();
            }
            for(int i = sz2-1; i >= 0; i--){
                v2[i] = st2.top();
                st2.pop();
            }

            vector<int>largest;
            int u = 0, v = 0;
            while(u < sz1 || v < sz2){
                if(u == sz1){
                    largest.push_back(v2[v++]);
                }else if(v == sz2){
                    largest.push_back(v1[u++]);
                }else if(v1[u] > v2[v]){
                    largest.push_back(v1[u]);
                    u++;
                }else if(v2[v] > v1[u]){
                    largest.push_back(v2[v]);
                    v++;
                }else{
                    int val = check(v1,v2,sz1,sz2,u,v);
                    if(val == 1){
                        largest.push_back(v1[u]);
                        u++;
                    }else{
                        largest.push_back(v2[v]);
                        v++;
                    }
                }
            }
            result = max(result,largest);
        }
        return result;
    }
};