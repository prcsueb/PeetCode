class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        int i = -1;
        int j = -1;
        map<char,int> visited;
        set<char> unique;
        for(int i=0;i<len;i++) {
            unique.insert(s[i]);
        }
        int ulen = unique.size();
        int olen = INT_MIN;
        
        while(i < len-1) {
            while(i < len-1) {
                ++i;
                visited[s[i]]++;
                if(visited[s[i]] > 1) {
                    break;
                }
                olen = max(olen, i - j);
            }
            cout << i << " " << j << endl;
            while(j < i) {
                cout << olen << endl;
                ++j;
                visited[s[j]]--;
                if(visited[s[j]] == 1) {
                    break;
                }
            }
        }
        
        return olen;
    }
};