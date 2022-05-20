class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=-1,j=-1;
        unordered_map<char,int> mp;
        int maxLen = 0;
        while(i < n-1) {
            while(i<n-1) {
                ++i;
                char ch = s[i];
                mp[ch]++;
                if(mp[ch] > 1) {
                    break;
                }
                maxLen = max(maxLen, i-j);
            }
            while(j<i) {
                ++j;
                char ch = s[j];
                mp[ch]--;
                if(mp[ch] == 1) {
                    break;
                }
            }
        }
        return maxLen;
    }
};