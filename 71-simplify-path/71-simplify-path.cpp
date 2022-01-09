class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if(path[n-1]!='/') {
            path+='/';
        }
        vector<string> stk;
        string curr = "";
        for(int i=1;i<path.length();i++) {
            //we are just processing content between two slashes
            if(path[i]=='/') {
                //process curr
                if(curr == "..") {
                    if(!stk.empty()) {
                        stk.pop_back();
                    }
                } else if(curr=="." || curr=="") {
                    
                } else {
                    //there is some file name
                    stk.push_back(curr);
                }
                curr="";
            } else {
                curr+=path[i];
            }
        }
        
        string ans="";
        bool flag=false;
        for(auto x:stk) {
            ans += x + "/";
            flag=true;
        }
        if(flag) ans.pop_back();
        
        return "/"+ans;
    }
};