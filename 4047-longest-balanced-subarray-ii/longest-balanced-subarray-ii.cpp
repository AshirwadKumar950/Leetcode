class SegmentTree{
    public: 
    //for min and max
    vector<pair<int,int>>seg;
    vector<int>lazy;

    SegmentTree(int n){
        seg.resize(4*n,{0,0});
        lazy.resize(4*n,0);
    }

    void propagation(int i, int l, int r){
        if(lazy[i] != 0){
            seg[i].first += lazy[i];
            seg[i].second += lazy[i];

            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    //l and r is the range of segment tree whereas start and end is our query size
    void updateRange(int start, int end, int i, int l, int r, int val){
        propagation(i,l,r);
        if(l > end || r < start) return;

        if(l >= start && r <= end){
            lazy[i] += val;
            propagation(i,l,r);
            return;
        }

        int mid = (l+r)/2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        seg[i].first = min(seg[2*i+1].first, seg[2*i+2].first);
        seg[i].second = max(seg[2*i+1].second, seg[2*i+2].second);
    }

    int findLeftMostZero(int l, int r, int idx){
        propagation(idx,l,r);
        if(seg[idx].first > 0 || seg[idx].second < 0) return -1;

        if(l == r) return l;

        int mid = (l+r) / 2;

        int leftResult = findLeftMostZero(l,mid,2*idx+1);
        if(leftResult != -1) return leftResult;

        return findLeftMostZero(mid+1,r,2*idx+2);
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>cumSum(n,0);

        int maxL = 0;
        unordered_map<int, int> mp;
        SegmentTree sg(n);
        for(int r = 0; r < n; r++){
            int val = (nums[r] % 2 == 0 ? 1 : -1);

            int prev = -1;
            if(mp.count(nums[r])){
                prev = mp[nums[r]];
            }

            if(prev != -1){
                sg.updateRange(0,prev,0,0,n-1,-val);
            }

            sg.updateRange(0,r,0,0,n-1,val);

            int l = sg.findLeftMostZero(0,n-1,0);
            if(l != -1) maxL = max(maxL, r - l + 1);

            mp[nums[r]] = r;
        }
        return maxL;
    }
};