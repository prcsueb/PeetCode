class Solution {
public:
    string strSort(string s) {
        string str="";
        vector<int> freq(26, 0);
        for(int i=0;i<s.length();i++) {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<freq.size();i++) {
            str += string(i + 'a', freq[i]);
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto s : strs) {
            mp[strSort(s)].push_back(s);
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