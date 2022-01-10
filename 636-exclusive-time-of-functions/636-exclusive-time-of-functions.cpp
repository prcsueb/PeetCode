class Solution {
public:
    struct Log{
        int id;
        int start;
        int child;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<Log> stk;
        for(int i=0;i<logs.size();i++) {
            stringstream ss(logs[i]);
            //convert stream and extract startTime,status,endTIme
            string id,status,startTime;
            getline(ss,id,':');
            getline(ss,status,':');
            getline(ss,startTime,':');
            
            //create strucutre out of it
            Log l = {stoi(id),stoi(startTime),0};
            if(status == "start") {
                stk.push(l);
            } else {
                //if it's ending time then calculate interval with and without interval
                //with child will be pushed to ans vector we add not override answer
                //without child will be pushed to child of top of the stack
                int intervalWithChild = stoi(startTime) - stk.top().start - stk.top().child + 1;
                int interval = stoi(startTime) - stk.top().start + 1;
                ans[stk.top().id] += intervalWithChild;
                stk.pop();
                if(!stk.empty()) {
                    stk.top().child += interval;
                }
            }
        }
        return ans;
    }
};