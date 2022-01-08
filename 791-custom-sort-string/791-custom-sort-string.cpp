class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> fr(26,0);
        for(int i=0;i<s.length();i++) {
            fr[s[i]-'a']++;
        }
        
        string ans = "";
        for(int i=0;i<order.length();i++) {
            char c = order[i];
            if(fr[c - 'a'] > 0) {
                for(int j=0;j<fr[c-'a'];j++) {
                    ans += c;
                }
                fr[c-'a']=0;
            }
        }
        for(int i=0;i<26;i++) {
            if(fr[i]>0) {
                for(int j=0;j<fr[i];j++) {
                    ans += i+'a';
                }
                fr[i]=0;
            }
        }
        return ans;
    }
};