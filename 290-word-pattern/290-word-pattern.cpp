class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream strs(s);
        string word;
        
        map<char,string> p2s;
        map<string,char> s2p;
        
        int i = 0;
        int n = pattern.length();
        
        for(; strs >> word; i++) {
            char che = pattern[i];
            string st = word;
            if(p2s.find(che) != p2s.end()) {
                if(p2s[che] != st) {
                    return false;
                }
            } else {
                p2s[che] = st;
            }
            
            if(s2p.find(st) != s2p.end()) {
                if(s2p[st] != che) {
                    return false;
                }
            } else {
                s2p[st] = che;
            }
        }
        
        return i == n;
    }
};