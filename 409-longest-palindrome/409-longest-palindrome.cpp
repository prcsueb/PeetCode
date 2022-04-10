class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int ans = 0;
        set<char> st;
        for(int i=0;i<n;i++) {
            auto it = st.find(s[i]);
            if(it == st.end()) {
                st.insert(s[i]);
            }
            else {
                ans += 2;
                st.erase(it);
            }
        }
        return st.size() == 0 ? ans:1+ans;
    }
};