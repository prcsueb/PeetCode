class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs) {
            string st = s;
            sort(st.begin(), st.end());
            mp[st].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++) {
            vector<string> intermediate;
            for(auto y : it->second) {
                intermediate.push_back(y);
            }
            ans.push_back(intermediate);
        }
        
        return ans;
    }
};