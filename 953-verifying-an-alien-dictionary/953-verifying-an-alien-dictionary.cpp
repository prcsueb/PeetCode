class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.size();i++) {
            mp[order[i]]=i;
        }
        
        for(int i=0;i+1<words.size();i++) {
            string word1=words[i];
            string word2=words[i+1];
            int minLen = word1.length();
            for(int j=0;j<minLen;j++) {
                if(j == word2.length()) {
                    return false;
                }
                if(word1[j] == word2[j]) {
                    continue;
                } else {
                    if(mp[word1[j]] > mp[word2[j]]) {
                        return false;
                    }
                    break;
                }
            }
            
        }
        
        
        return true;
    }
};