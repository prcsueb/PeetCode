class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0;
        int j=0;
        int ws = word.size();
        int as = abbr.size();
        while(i < ws && j < as) {
            if(isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                int val = 0;
                while(isdigit(abbr[j]) && j < as) {
                    val = (val * 10 + abbr[j++]-'0');
                }
                i+=val;
            } else {
                if(word[i++] != abbr[j++]) {
                    return false;
                }
            }
        }
        return i == ws && j == as;
    }
};