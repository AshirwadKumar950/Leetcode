class Solution {
public:
    typedef tuple<int,int,char> tup;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tup>arr;
        for(int i = 0; i < n; i++){
            arr.push_back(make_tuple(positions[i],healths[i],directions[i]));
        }
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n; i++){
            auto [a,b,c] = arr[i];
            cout<<a<<" "<<b<<" "<<c<<endl;
            // cout<<"["<<a<<", "<<b<<", "<<c<<"] ";
        }
        stack<tup>st;// direction, health
        for(int i = 0; i < n; i++){
            // int x = 
            // while(!st.empty() && st.top.first() == 'R' && directions[i])
            auto [a1,b1,c1] = arr[i];
            bool topush = true;
            while(!st.empty() && get<2>(st.top()) == 'R' && c1 == 'L'){
                auto [a,b,c] = st.top();
                st.pop();
                if(b > b1){
                    b--;
                    st.push({a,b,c});
                    topush = false;
                    break;
                }else if(b1 > b){
                    b1--;
                }else{
                    topush = false;
                    break;
                }
            }
            if(topush) st.push(make_tuple(a1,b1,c1));
        }
        unordered_map<int,int>mp;
        while(!st.empty()){
            auto [a,b,c] = st.top();
            mp[a] = b;
            st.pop();
        }
        vector<int>res;
        for(int i = 0; i < n; i++){
            if(mp.find(positions[i]) != mp.end()){
                res.push_back(mp[positions[i]]);
            }
        }
        return res;

        /*
        [14,L], [16,L], [19,L], [30,L], [24,R]
        */
    }
};