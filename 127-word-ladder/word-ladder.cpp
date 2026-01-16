class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            first brute force approach build a graph or queue
            starting from beginWord and with one char diff pick 
            those words and add it to queue and if we reach the end 
            count the minimum no of moves taken
        */
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>used;
        int size = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto p = q.front();
                q.pop();
                if(p == endWord) return size;
                for(auto &word : wordList){
                    if(used.count(word)) continue;
                    int l = p.length();
                    int c = 0;
                    for(int i = 0; i < l; i++){
                        if(word[i] != p[i]) c++;
                        if(c > 1) break;
                    }
                    if(c == 1) {
                        q.push(word);
                        used.insert(word);
                    }
                }
            }
            size++;
        }
        return 0;
    }
};