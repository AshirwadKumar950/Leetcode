class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> pii;
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        //keep all the incr - dec - incr aubarray starting and
        //ending point in an array and make with this an array 
        //and apply dp there
        vector<pii>dpL(n,{0,0}), dpR(n,{0,0});
        vector<ll>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        ll sum = nums[0];
        //left increaisng value 
        ll length = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
                length++;
            }else{
                sum = nums[i];
                length = 1;
            }
            if(length > 2 && sum < nums[i]+nums[i-1]) sum = nums[i]+nums[i-1]; 
            dpL[i] = {sum,length};
        }
        sum = nums[n-1];
        length = 1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                sum += nums[i];
                length++;
            }else{
                sum = nums[i];
                length = 1;
            }
            if(length > 2 && sum < nums[i]+nums[i+1]) sum = nums[i]+nums[i+1]; 
            dpR[i] = {sum,length};
        }
        // for(int i = 0; i < n; i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<"["<<dpL[i].first<<","<<dpL[i].second<<"]"<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<"["<<dpR[i].first<<","<<dpR[i].second<<"]"<<" ";
        // }
        cout<<endl;
        ll ans = LLONG_MIN;
        int i = 0;
        while(i < n-1){
            if(nums[i] > nums[i+1] && i > 0){
                int start = i;
                while(i < n-1 && nums[i] > nums[i+1]) i++;

                int end = i;
                //cout<<start<<" "<<end<<endl;
                ll decsum = 0;
                if(start < end-1)
                decsum = prefix[end-1 ] - prefix[start];
                if(start > 0 && end < n-1){
                    pii leftV = dpL[start];
                    pii rightV = dpR[end];
                    // if(leftV.second >=2 && rightV.second >= 2){
                        ans = max(ans,decsum+leftV.first+rightV.first);
                    // }
                }
            }else{
                i++;
            }
        }
        return ans;
    }
};