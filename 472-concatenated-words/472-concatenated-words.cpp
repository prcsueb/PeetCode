class Solution {
public:
    class TrieNode {
        public:
        TrieNode *children[26]  ;
        bool isEnd;
        string str;
        TrieNode() {
            for(int i=0;i<26;i++) {
                this->children[i]=NULL;
                this->isEnd = false;
                this->str="";
            }
        }
    };
    
    void insert(string word) {
        if(word=="")return;
        TrieNode *ptr = root;
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ptr->children[ch-'a'] == NULL) {
                ptr->children[ch-'a'] = new TrieNode();
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isEnd = true;
        ptr->str=word;
    }
    vector<string> result;
    void search2(TrieNode *curr, TrieNode *nWord) {
        if(curr->isEnd==true && nWord->isEnd==true) {
            result.push_back(curr->str);
            curr->isEnd = false;
        }
        if(nWord->isEnd==true) {
            search2(curr, root);
        }
        for(int i=0;i<26;i++) {
            if(curr->children[i]!=NULL && nWord->children[i]!=NULL) {
                search2(curr->children[i],nWord->children[i]);
            }
        }
    }
    
    void search1(TrieNode *curr) {
        if(curr->isEnd == true) {
            search2(curr,root);
        }
        
        for(int i=0;i<26;i++) {
            if(curr->children[i] != NULL) {
                search1(curr->children[i]);
            }
        }
    }
    
    TrieNode *root;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        
        for(auto x : words) {
            insert(x);
        }
        
        search1(root);
        
        return result;
    }
};