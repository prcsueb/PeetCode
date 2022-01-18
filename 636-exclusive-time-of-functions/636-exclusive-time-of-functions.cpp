class Solution {
public:
    struct Log {
        int id;
        int start;
        int child;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Log> stk;
        vector<int> ans(n);
        for(int i=0;i<logs.size();i++) {
            string log = logs[i];
            stringstream ss(log);
            string id,status,startTime;
            getline(ss,id,':');
            getline(ss,status,':');
            getline(ss,startTime,':');
            Log l = {stoi(id),stoi(startTime),0};
            if(status == "start") {
                stk.push(l);
            } else {
                int intervalWithOutChild = stoi(startTime)-stk.top().start+1;
                int intervalWithChild = stoi(startTime)-stk.top().start-stk.top().child+1;
                ans[stk.top().id]+=intervalWithChild;
                stk.pop();
                if(!stk.empty()) {
                    stk.top().child+=intervalWithOutChild;
                }
            }
        }
        return ans;
    }
};