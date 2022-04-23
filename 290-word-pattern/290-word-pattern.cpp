class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> c2s;
        map<string,char> s2c;
        string word;
        istringstream strs(s);
        int i=0;
        for(;strs >> word;i++) {
            char chFirst = pattern[i];
            string wdFirst = word;
            if(c2s.find(chFirst) != c2s.end()) {
                if(c2s[chFirst] != wdFirst) {
                    return false;
                }
            } else {
                c2s[chFirst] = wdFirst;
            }
            
            if(s2c.find(wdFirst) != s2c.end()) {
                if(s2c[wdFirst] != chFirst) {
                    return false;
                }
            } else {
                s2c[wdFirst] = chFirst;
            }
        }
        return i == pattern.length();
    }
};