class Solution {
public:
    //4.compare maps function
    bool cmp(map<char,int> &pmap, map<char,int> &smap) {
        for(auto it=smap.begin();it!=smap.end();it++) {
            if(smap[it->first] == pmap[it->first]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<int> ans;
        map<char,int> pmap;
        map<char,int> smap;
        
        //1.create pattern map
        for(auto c : p) {
            pmap[c]++;
        }
        
        //2.create string map of pattern.length() size
        for(int i=0;i<plen;i++) {
            smap[s[i]]++;
        }
        
        //3.sliding window and compare 2 maps and store indexes
        int i = plen;
        while(i < slen) {
            if(cmp(pmap, smap)) {
                ans.push_back(i - plen);
            }
            char c = s[i];
            smap[c]++;
            //if freque becomes zero then remove from map
            if(smap[s[i - plen]] == 1) {
                smap.erase(smap.find(s[i - plen]));
            } else {
                smap[s[i - plen]]--;
            }
            i++;
        }
        if(cmp(pmap, smap)) {
            ans.push_back(i - plen);
        }
        
        
        //5.return index vector
        return ans;
    }
};