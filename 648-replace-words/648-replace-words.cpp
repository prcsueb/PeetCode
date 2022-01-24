class Solution {
public:
    class TrieNode{
        public:
        TrieNode *children[26];
        bool isEnd;
        TrieNode() {
            for(int i=0;i<26;i++) {
                this->children[i]=NULL;
            }
            isEnd=false;
        }
    };
    TrieNode *root = NULL;
    
    void insert(string word) {
        TrieNode *ptr = root;
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ptr->children[ch-'a'] == NULL) {
                ptr->children[ch-'a'] = new TrieNode();
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isEnd = true;
    }
    
    string queryWords(string &word) {
        string sub="";
        TrieNode *ptr = root;
        for(auto ch : word) {
            if(ptr->children[ch-'a']==NULL) {
                break;
            }
            sub+=ch;
            ptr=ptr->children[ch-'a'];
            if(ptr->isEnd == true) {
                return sub;
            }
        }
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for(int i=0;i<dictionary.size();i++) {
            insert(dictionary[i]);
        }
        stringstream ss(sentence);
        string str;
        string ans = "";
        for(;ss>>str;) {
            str = queryWords(str);
            ans+=str;
            ans.push_back(' ');
        }
        ans.pop_back();
        
        return ans;
    }
};



//the abcd bcd
// a b
//a 












