class Solution {
public:
    class TrieNode{
        public:
        TrieNode *children[26];
        bool isEnd;
        int frequency;
        TrieNode() {
            for(int i=0;i<26;i++) {
                this->children[i]=NULL;
            }
            isEnd=false;
            this->frequency=0;
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
            ptr->frequency++;
        }
        ptr->isEnd = true;
    }
    
    int searchWord(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited, string &str, TrieNode *root, vector<vector<int>> &dir, vector<string> &result) {
        char ch = board[i][j];
        if(root->children[ch-'a'] == NULL) {
            return 0;
        }
        
        root = root->children[ch-'a'];
        if(root->frequency == 0) {
            return 0;
        }
        
        visited[i][j] = true;
        
        int count = 0;
        str.push_back(ch);
        if(root->isEnd == true) {
            result.push_back(str);
            root->isEnd = false;
            count = 1;
        }
        
        for(auto d : dir) {
            int newRow = i + d[0];
            int newCol = j + d[1];
            if(newRow >= 0 && newCol >= 0 && newRow < board.size() && newCol < board[0].size() && visited[newRow][newCol]==false) {
                 count += searchWord(board,newRow,newCol,visited,str,root,dir,result);
            }
        }
        
        visited[i][j]=false;
        str.pop_back();
        root->frequency-=count;
        return count;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        vector<string> result;
        //insert
        for(int i=0;i<words.size();i++) {
            insert(words[i]);
        }
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        TrieNode *ptr = root;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                string str = "";
                searchWord(board,i,j,visited,str,root,dir,result);
            }
        }
        
        return result;
    }
};

















