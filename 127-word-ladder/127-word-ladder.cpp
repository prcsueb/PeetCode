class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> s;
        int n = wordList.size();
        for(int i=0;i<n;i++) {
            s.insert(wordList[i]);
        }
        if(s.find(end)==s.end()) return 0;
        queue<string> q;
        q.push(start);
        int level=0;
        while(!q.empty()) {
            int size = q.size();
            level++;
            while(size--) {
                string front = q.front();
                q.pop();
                for(int i=0;i<front.length();i++) {
                    char charStore = front[i];
                    for(int j=0;j<26;j++) {
                        char replaceChar = (char)(j+97);
                        front[i]=replaceChar;
                        if(front==end) {
                            return level+1;
                        } else if(s.find(front)!=s.end()) {
                            q.push(front);
                            s.erase(front);
                        }                        
                    }
                    front[i]=charStore;
                }
            }
        }
        return 0;
    }
};