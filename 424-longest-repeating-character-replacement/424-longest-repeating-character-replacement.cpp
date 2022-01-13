class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int maxi=0;
        int i=0;
        int j=0;
        map<char,int> mp;
        int slen = s.length();
        int maxFrequency=0;
        
        while(j<slen) {
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            
            if((j-i+1)-maxi>k) {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};