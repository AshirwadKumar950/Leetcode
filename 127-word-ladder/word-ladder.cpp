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
        unordered_set<string>words(wordList.begin(),wordList.end());
        int size = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                if(p == endWord) return size;
                
                int l = p.length();
                for(int i = 0; i < l; i++){
                    for(int j = 0; j < 26; j++){
                        string copy = p;
                        char newchar = j + 'a';
                        if(p[i] == newchar) continue;

                        copy[i] = newchar;
                        if(words.find(copy) != words.end()){
                            q.push(copy);
                            words.erase(copy);
                        }
                    }
                }
            }
            size++;
        }
        return 0;
    }
};