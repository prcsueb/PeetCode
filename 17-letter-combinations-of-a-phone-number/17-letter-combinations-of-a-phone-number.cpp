class Solution {
public:
    vector<string> phone = {{".;"},{".;"},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    vector<string> helper(string s) {
      if(s.length()==0) {
          vector<string> base;
          base.push_back("");
          return base;
      }
      char c = s[0];
      string comb = phone[c-'0'];
      vector<string> rec = helper(s.substr(1));
      vector<string> ans;
      for(int i=0;i<comb.length();i++) {
          for(int j=0;j<rec.size();j++) {
              string x="";
              x+=comb[i];
              x+=rec[j];
              ans.push_back(x);
          }
      }
      return ans;
    }
    vector<string> letterCombinations(string s) {
        if(s.length()==0)return{};
        return helper(s);
    }
};