class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool searchHelper(TrieNode *ptr, string word, int idx) {
        if(word.length() == idx) {
            return ptr->isEnd;
        }
        char ch = word[idx];
        if(ch == '.') {
            for(int i=0;i<26;i++) {
                TrieNode *child = ptr->children[i];
                if(child != NULL && searchHelper(child,word,idx+1) == true) {
                    return true;
                }
            }
        } else if(ptr->children[ch-'a'] != NULL) {
            return searchHelper(ptr->children[ch-'a'],word,idx+1);
        }
        return false;
    }
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */