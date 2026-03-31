class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int sz = n + m - 1;
        string word(sz, '$');
        // Step 1: Apply 'T' constraints
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '$') {
                        word[i + j] = s2[j];
                    }
                    else if (word[i + j] != s2[j]) {
                        return "";
                    }
                }
            }
        }

        // Step 2: Copy original state
        string word2 = word;

        // Step 3: Process 'F' constraints
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'F') {

                int cntBlank = 0, cntSame = 0;
                int lastBlank = -1;

                for (int j = 0; j < m; j++) {

                    if (word2[i + j] == '$') {
                        if (word[i + j] == '$') {
                            word[i + j] = 'a';
                        }
                        lastBlank = i + j;
                        cntBlank++;
                    }

                    if (word[i + j] == s2[j]) {
                        cntSame++;
                    }
                }

                if ((cntSame == m) && (cntBlank == 0)) return "";

                if ((cntSame == m) && (cntBlank > 0)) {
                    word[lastBlank] = 'b';
                }
            }
        }

        return word;
    }
};