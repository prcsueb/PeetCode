class Solution {
public:
    void processString(string s, map<string,vector<string>> &mp) {
        int slen = s.length();
        if(slen == 1) {
            mp["."].push_back(s);
            return;
        }
        string key = "";
        for(int i=1;i<slen;i++) {
            char curr = s[i];
            char prev = s[i-1];
            int diff = curr - prev;
            if(diff < 0) {
                diff += 26;
            }
            string diffStr = to_string(diff) + "#";
            key += (diffStr);
        }
        key += (".");
        mp[key].push_back(s);
        return;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        
        for(auto x : strings) {
           processString(x, mp);
        } 
        
        //fill answer
        for(auto it=mp.begin();it!=mp.end();it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};