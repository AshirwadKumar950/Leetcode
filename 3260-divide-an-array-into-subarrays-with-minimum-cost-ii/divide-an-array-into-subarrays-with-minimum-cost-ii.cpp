class Solution {
public:
    typedef long long ll;
    typedef pair<int,int> pii;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = LLONG_MAX;
        int n = nums.size();

        set<pii> isin,afterK;
        ll sum = 0;
        
        int go = min(n-1,1 + dist);
        for(int i = 1; i <= go; i++){
            isin.insert({nums[i],i});
            if(isin.size() > k-1){
                auto it =isin.end();
                --it;
                afterK.insert(*it);
                isin.erase(it);
            }
        }
        for(auto it = isin.begin(); it != isin.end(); ++it){
            sum += it->first;
        }
        
        ans = sum;
        //cout<<ans<<endl;
        int l = 1;
        /*
            now in sliding window my window will shrink from left by 1 and increase 
            to right by 1 so first I check if left element which went out was in my 
            sum if yes remove this value from sum. and get the smallest values 
            from afterK and add in sum and now I received the right side element 
            which entered just now check if it is less than prev(sin.end()) 
            is yes remove last from sum put this value in sum and insert last in afterK
        */
        for(int r = dist+2; r < n; r++,l++){
            //it means this value is in top k sum
            //remove this from sum
            if(isin.find({nums[l],l}) != isin.end()){
                isin.erase({nums[l],l});

                sum -= nums[l];
                //get the smallest from afterK
                if(!afterK.empty()){
                    auto it = afterK.begin();
                    sum += it->first;
                    isin.insert(*it);
                    afterK.erase(it);
                }
               
            }else{
                afterK.erase({nums[l],l});
            }

            //now i have remove left if it was and added another smaller in place it is balanced
            //now i will see if new comer can be smaller than k-1
            
            isin.insert({nums[r],r});
            sum += nums[r];

            if(isin.size() > k-1){
                auto it = prev(isin.end());
                sum -= it->first;
                afterK.insert(*it);
                isin.erase(it);
            }
            
            ans = min(ans,sum);
        }
        return ans+1ll*nums[0];
    }
};
