class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int addr1=-1;
        int addr2=-1;
        int minDist = INT_MAX;
        for(int i=0;i<wordsDict.size();i++) {
            if(wordsDict[i] == word1) {
                addr1 = i;
            }
            if(wordsDict[i] == word2) {
                addr2 = i;
            }
            if(addr1!=-1 && addr2!=-1) {
                minDist = min(minDist, abs(addr1-addr2));
            }
        }
        
        return minDist;
    }
};