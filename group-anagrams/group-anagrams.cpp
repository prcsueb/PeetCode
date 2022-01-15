class Solution {
public:
    map<map<char,int>,vector<string>> mp;
    void processStr(string str) {
        
        map<char,int> freMap;
        if(str=="") {
            freMap['.']++;
            mp[freMap].push_back("");    
            return;
        }
        for(int i=0;i<str.length();i++) {
            freMap[str[i]]++;
        }
        mp[freMap].push_back(str);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++) {
            processStr(strs[i]);
        }
        for(auto x : mp) {
            vector<string> a = x.second;
            vector<string> intermediate;
            for(auto y : a) {
                intermediate.push_back(y);
            }
            ans.push_back(intermediate);
        }
        return ans;
    }
};