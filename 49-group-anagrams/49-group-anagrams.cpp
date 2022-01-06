class Solution {
public:
    void processString(string s, map<map<char,int>,vector<string>> &mp) {
        int slen = s.length();
        map<char,int> frequeMp;
        for(int i=0;i<slen;i++) {
            frequeMp[s[i]]++;
        }
        mp[frequeMp].push_back(s);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char,int>,vector<string>> mp;
        for(auto x : strs) {
            //process and fill map
            processString(x, mp);
        }
        //fill ans using map
        for(auto it=mp.begin();it!=mp.end();it++) {
            ans.push_back(it->second);
        }
        //return answer
        return ans;
    }
};