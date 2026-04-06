class Solution {
public:
    char changeDirection(char curr, char dir){
        if(curr == 'N') return dir == 'L' ? 'W' : 'E';
        if(curr == 'S') return dir == 'L' ? 'E' : 'W';
        if(curr == 'E') return dir == 'L' ? 'N' : 'S';
        if(curr == 'W') return dir == 'L' ? 'S' : 'N';
        return 'C';
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int,int>>mp;
        for(auto &obs : obstacles){
            mp.insert({obs[0],obs[1]});
        }
        int x = 0, y = 0;
        int ans = 0;
        char direction = 'N';
        bool start = false;
        for(int i = 0; i < n; i++){
            int v = commands[i];
            if(v > 0){
                if(direction == 'N'){
                    for(int i = 1;i <= v; i++){
                        if(mp.find({x,y+1})!=mp.end()){
                            break;
                        }
                        y++;
                    }
                }else if(direction == 'E'){
                    for(int i = 1;i <= v; i++){
                        if(mp.find({x+1,y})!=mp.end()){
                            break;
                        }
                        x++;
                    }
                }else if(direction == 'S'){
                    for(int i = 1;i <= v; i++){
                        if(mp.find({x,y-1})!=mp.end()){
                            break;
                        }
                        y--;
                    }
                }else{
                    for(int i = 1;i <= v; i++){
                        if(mp.find({x-1,y})!=mp.end()){
                            break;
                        }
                        x--;
                    }
                }
            }else 
            direction = changeDirection(direction, v == -1 ? 'R' : 'L');
            ans = max(ans, (x*x+y*y));
        }
        return ans;
    }
};