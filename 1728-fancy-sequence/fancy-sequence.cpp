typedef long long ll;
const int MOD = 1e9 + 7;
class SegmentTree{
    public:
    vector<ll>seg, lazymul, lazyadd;
    
    SegmentTree(int n){
        seg.resize(4*n,0);
        lazyadd.resize(4*n,0);
        lazymul.resize(4*n,1);
    }

    // l and r is left and right of the array and start and end is segtree size and idx is where to put tha val
    void insert(int l, int r, int i, int idx, int val){
        if(l == r){
            seg[i] = val;
            return;
        }

        int mid = (l+r)/2;
        if(idx <= mid) insert(l, mid, 2*i+1, idx, val);
        else insert(mid+1,r, 2*i+2, idx, val);
        seg[i] = (seg[2*i+1] + seg[2*i+2]) % MOD; 
    }

    void apply(int node,int l,int r,long long mul,long long add){
        seg[node] = (seg[node]*mul % MOD + add*(r-l+1)%MOD) % MOD;
        lazymul[node] = lazymul[node]*mul % MOD;
        lazyadd[node] = (lazyadd[node]*mul % MOD + add) % MOD;
    }

    void push(int node,int l,int r){

        if(lazymul[node]==1 && lazyadd[node]==0) return;

        int mid=(l+r)/2;

        apply(2*node+1,l,mid,lazymul[node],lazyadd[node]);
        apply(2*node+2,mid+1,r,lazymul[node],lazyadd[node]);

        lazymul[node]=1;
        lazyadd[node]=0;
    }
    void update(int node,int l,int r,int ql,int qr,ll mul,ll add){

        if(qr < l || ql > r) return;

        if(ql <= l && r <= qr){
            apply(node,l,r,mul,add);
            return;
        }

        push(node,l,r);

        int mid=(l+r)/2;

        update(2*node+1,l,mid,ql,qr,mul,add);
        update(2*node+2,mid+1,r,ql,qr,mul,add);

        seg[node]=(seg[2*node+1]+seg[2*node+2])%MOD;
    }

    ll query(int node,int l,int r,int idx){

        if(l==r) return seg[node];

        push(node,l,r);

        int mid=(l+r)/2;

        if(idx<=mid) return query(2*node+1,l,mid,idx);
        else return query(2*node+2,mid+1,r,idx);
    }
};
class Fancy {
public:
    SegmentTree st;
    int size;

    Fancy(): st(100000) {
        size = 0;
    }

    void append(int val) {
        st.insert(0,100000-1,0,size,val);
        size++;
    }

    void addAll(int inc) {
        if(size==0) return;
        st.update(0,0,100000-1,0,size-1,1,inc);
    }

    void multAll(int m) {
        if(size==0) return;
        st.update(0,0,100000-1,0,size-1,m,0);
    }

    int getIndex(int idx) {
        if(idx>=size) return -1;
        return st.query(0,0,100000-1,idx);
    }
};