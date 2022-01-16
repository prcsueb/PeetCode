class Trie {
public:
    class TrieNode {
        public:
        char ch;
        TrieNode* children[26] = {nullptr};
        bool isWord;
        TrieNode(char ch) {
            this->isWord = false;
            this->ch=ch;
        }
    };
    
    TrieNode *root;
    
    Trie() {
        root = new TrieNode(' ');
    }
    
    void insert(string word) {
        TrieNode *ptr = root;
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ptr->children[ch-'a'] == NULL) {
                ptr->children[ch-'a'] = new TrieNode(ch);
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *ptr = root;
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ptr->children[ch-'a']==NULL) {
                return false;
            }
            ptr=ptr->children[ch-'a'];
        }
        return (ptr->isWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for(int i=0;i<prefix.length();i++) {
            char ch = prefix[i];
            if(ptr->children[ch-'a']==NULL) {
                return false;
            }
            ptr=ptr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */










