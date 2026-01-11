class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        stack<int>st;
        for(int i = 0; i < n; i++){
            //current bar is right boundry for taller bars
            while(!st.empty() && heights[st.top()] > heights[i]){
                int tp = st.top();
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;
                maxarea = max(maxarea, width*heights[tp]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int tp = st.top();
            st.pop();
            int right = n;
            int left = st.empty() ? -1 : st.top();
            int width = right - left - 1;
            maxarea = max(maxarea, width*heights[tp]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[j][i] == 0) continue;
                mat[j][i] = mat[j][i] + mat[j-1][i];
            }
        }
        int maxarea = 0;
        for(int i = 0; i < m; i++){
            maxarea = max(maxarea,largestRectangleArea(mat[i]));
        }
        return maxarea;
    }
};