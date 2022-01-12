class Solution {
public:
    class Pair{
      public:
        int dist;
        int ele;
        Pair(int d,int e) {
            dist=d;
            ele=e;
        }
    };
    class Compare {
        public:
        bool operator()(Pair a, Pair b) {
            return a.dist < b.dist;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<Pair,vector<Pair>,Compare> pq;
        
        for(int i=0;i<n;i++) {
            if(pq.size() < k) {
                int dist = abs(arr[i]-x);
                pq.push(Pair(dist,arr[i]));
            } else {
                Pair top = pq.top();
                int dist = top.dist;
                int ele = top.ele;
                if(dist > abs(arr[i]-x)) {
                    pq.pop();
                    pq.push({abs(arr[i]-x), arr[i]});
                }
            }
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().ele);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};