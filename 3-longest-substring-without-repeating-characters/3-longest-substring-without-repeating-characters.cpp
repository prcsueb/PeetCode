class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        int i = -1;
        int j = -1;
        map<char,int> mp;
        int ans=0;
        
        while(i < len-1) {
            while(i < len-1) {
                ++i;
                mp[s[i]]++;
                if(mp[s[i]]>1) {
                    break;
                }
                ans=max(ans,i-j);
            }
            while(j < i) {
                ++j;
                mp[s[j]]--;
                if(mp[s[j]]==0) {
                    mp.erase(mp.find(s[j]));
                }
                if(mp[s[j]]==1) {
                    break;
                }
            }
        }
        
        return ans;
    }
};