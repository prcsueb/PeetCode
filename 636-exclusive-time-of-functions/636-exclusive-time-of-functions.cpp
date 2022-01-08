class Solution {
public:
    struct Log {
        int id;
        int start;
        int child;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        //store execuition time of each function
        vector<int> timeF(n);
        stack<Log> stk;
        
        for(string log : logs) {
            //extract starting time, status and ending time
            stringstream ss(log);
            
            string startTime,status,endTime;
            getline(ss,startTime,':');
            getline(ss,status,':');
            getline(ss,endTime,':');
            
            Log item = {stoi(startTime),stoi(endTime),0};//using struct
            
            if(status == "start") {
                stk.push(item);
            } else {
                //ending 
                Log top = stk.top();
                stk.pop();
                int interval = stoi(endTime) - top.start + 1;
                int timeOfExe = interval - top.child;
                timeF[top.id]+=timeOfExe;
                if(stk.size() > 0) {
                    stk.top().child+=interval;
                }
            }
        }
        return timeF;
    }
};