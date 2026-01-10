class SegmentTree{
    vector<int>seg;
    int n;
    public:
    SegmentTree(int n){
        this->n = n;
        seg.assign(4*n,-1e9);
    }
    //while i am building i am making a segment tree which contains the max fruit from its left and right subtree
    void build(int idx, int start, int end, vector<int>&nums){
        if(start == end){
            seg[idx] = nums[start];
            return; 
        }
        int mid = (start+end)/2;
        build(2*idx+1,start,mid,nums);
        build(2*idx+2,mid+1,end,nums);
        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }

    //this function would give me the leftmost index of the biggest basket
    int query(int i, int l, int r, int x){
        if(seg[i] < x) return -1;

        if(l == r) return l;

        int mid = l + (r-l)/2;
        if(seg[2*i+1] >= x){
            return query(2*i+1,l,mid,x);
        }
        return query(2*i+2,mid+1,r,x);
    }

    void update(int i, int l, int r, int pos){
        if(l == r){
            seg[i] = -1e9;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*i+1,l,mid,pos);
        else update(2*i+2,mid+1,r,pos);
        seg[i] =max(seg[2*i+1],seg[2*i+2]);
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        SegmentTree st(n);
        st.build(0,0,n-1,baskets);
        int count = 0;
        for(int i = 0; i < n; i++){
            int idx = st.query(0,0,n-1,fruits[i]);

            if(idx != -1){
                count++;
                st.update(0,0,n-1,idx);
            }
        }
        return n-count;
    }
};