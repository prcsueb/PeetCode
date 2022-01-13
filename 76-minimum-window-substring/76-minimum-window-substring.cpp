class Solution {
public:
    string minWindow(string s, string t) {
        int slen=s.length();
        int tlen=t.length();
        if(tlen>slen) {
            return "";
        }
        int i=-1;
        int j=-1;
        int matchCount=0;
        map<char,int> smap;
        map<char,int> tmap;
        int start=-1;
        int end=-1;
        int ans=INT_MAX;
        for(int i=0;i<tlen;i++) {
            tmap[t[i]]++;
        }
        while(i<slen) {
            while(i<slen && matchCount<tlen) {
                ++i;
                smap[s[i]]++;
                if(tmap[s[i]] > 0 && smap[s[i]]<=tmap[s[i]]) {
                    matchCount++;
                }
            }   
            while(matchCount==tlen && j<i) {
                int len = i-j;
                if(len<ans) {
                    ans=len;
                    end=i;
                    start=j+1;
                }
                ++j;
                smap[s[j]]--;
                if(tmap[s[j]] > 0 && smap[s[j]]<tmap[s[j]]) {
                    matchCount--;
                }
            }
        }
        if(start==-1 && end==-1) {
            return "";
        }
        string ansString="";
        for(int x=start;x<=end;x++) {
            ansString += s[x];
        }
        return ansString;
    }
};