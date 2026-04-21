class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = st.lower_bound({startTime, endTime});

        // it retuns first value >= startTime
        if(it != st.end() && it->first < endTime){
            return false;
        }

        if(it != st.begin()){
            auto prev = it;
            prev--;
            if(prev->second > startTime){
                return false;
            }
        }
        st.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */