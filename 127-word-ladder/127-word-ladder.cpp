class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> s;
        int n = wordList.size();
        for(int i=0;i<n;i++) {
            s.insert(wordList[i]);
        }
        if(s.find(end)==s.end())return 0;
        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            level++;
            while(size--) {
                string front = q.front();
                q.pop();
                for(int i=0;i<front.length();i++) {
                    char ch = front[i];
                    for(int j=0;j<26;j++) {
                        char replace = (char)(j+97);
                        front[i]=replace;
                        if(front==end) {
                            return level+1;
                        }
                        if(s.find(front)!=s.end()) {
                            s.erase(front);
                            q.push(front);
                        }
                    }
                    front[i]=ch;
                }
            }
        }
        return 0;
    }
};