class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for(int i=0;i<s.length();i++) {
            count[s[i]-'a']++;
        }
        
        int maxChar=0;
        int maxCount=0;
        
        for(int i=0;i<26;i++) {
            if(maxCount < count[i]) {
                maxCount = count[i];
                maxChar = i;
            }
        }
        
        if(maxCount > (s.length()+1)/2) {
            return "";
        }
        
        string res=s;
        int i=0;
        
        while(count[maxChar] > 0) {
            res[i] = char(maxChar+'a');
            count[maxChar]--;
            i+=2;
        }
        
        for(int idx=0;idx<26;idx++) {
            while(count[idx] > 0) {
                if(i >= s.length()) {
                    i = 1;
                }
                res[i] = char(idx+'a');
                count[idx]--;
                i+=2;
            }
        }
        
        return res;
    }
};