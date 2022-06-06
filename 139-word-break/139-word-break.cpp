class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int nWords = wordDict.size();
        int len = 0;
        for(auto &s : wordDict) {
            st.insert(s);
            if(s.length() > len) {
                len = s.length();
            }
        }
        cout << len << endl;
        
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i=0;i<=s.length();i++) {
            if(!dp[i]) {
                continue;
            }
            for(int l=1;l<=len && i+l < dp.size();l++) {
                string word = s.substr(i, l);
                if(st.find(word) != st.end()) {
                    dp[i + l] = true;
                }
            }
        }
        
        return dp[s.length()];
    }
};