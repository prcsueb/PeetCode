class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        map<string,multiset<string>> mp; //multiset to make lexico sorted
        
        //create map
        for(auto &x : tickets) {
            mp[x[0]].insert(x[1]);
        }
        
        stack<string> stk;
        stk.push("JFK"); //always starts from JFK only
        vector<string> ans;
        
        while(!stk.empty()) {
            string top = stk.top();
            
            if(mp[top].size() == 0) {
                ans.push_back(top);
                stk.pop();
            } else {
                string first = *mp[top].begin(); //putted * to convert iterator pointer to value
                stk.push(first);
                mp[top].erase(mp[top].find(first));
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};