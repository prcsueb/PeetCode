class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int slen = s.length();
        if(k == 0) {
            return 0;
        }
        
        int i = -1;
        int j = -1;
        map<char,int> mp;
        int maxLen = INT_MIN;
        
        while(i < slen - 1) {
            while(i < slen - 1) {
                ++i;
                mp[s[i]]++;
                if(mp.size() == k + 1) {
                    break;
                }
                maxLen = max(maxLen, i - j);
            }
            
            while(j < i) {
                ++j;
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    mp.erase(mp.find(s[j]));
                }
                if(mp.size() == k) {
                    break;
                }
            }
        }
        
        return maxLen;
    }
};