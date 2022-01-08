class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        map<int,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]-'0'] = i;
        }
        for(int i=0;i<s.length();i++) {
            for(int j=9;j>s[i]-'0';j--) {
                if(mp[j] > i) {
                    swap(s[mp[j]], s[i]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};