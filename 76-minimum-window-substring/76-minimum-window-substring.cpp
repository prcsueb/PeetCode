class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) {
            return "";
        }
        map<char,int> t_map;
        for(int i=0;i<t.size();i++) {
            t_map[t[i]]++;
        }
        
        map<char,int> s_map;
        int start = -1;
        int end = -1;
        int i=-1;
        int j=-1;
        int mc = 0;
        int olen = INT_MAX;
        
        int slen = s.length();
        int tlen = t.length();
        
        while(i < slen) {
            // cout << "whiile1" << endl;
            bool flag1 = false;
            bool flag2 = false;
            
            while(i < slen && mc < tlen) {
                
                flag1 = true;
                ++i;
                s_map[s[i]]++;
                if(t_map[s[i]] > 0 && s_map[s[i]] <= t_map[s[i]]) {
                    // cout << mc << endl;
                    cout << s[i] << " , ";
                    mc++;
                }
            }
            cout << "mc = " << mc << " i = " << i << endl;
            
            while(mc == tlen && j < i) {
                flag2 = true;
                int len = i - j;
                if(len < olen) {
                    olen = len;
                    start = j+1;
                    end = i;
                    cout << "len = "  << len << " olen = " << olen << endl;
                }
                ++j;
                
                s_map[s[j]]--;
                if(t_map[s[j]] > 0 && s_map[s[j]] < t_map[s[j]]) {
                    mc--;
                }
            }
            
            if(!flag1 && !flag2) {
                break;
            }
        }
        cout << start << " " << end << endl;
        if(start == -1 && end == -1) {
            return "";
        }
        
        string ans = "";
        for(int x=start;x<=end;x++) {
            ans += s[x];
        }
        
        
        return ans;
    }
};