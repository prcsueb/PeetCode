class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //most optimal solution
        //ds : dequeue
        //space: o(K) time: o(N)
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<nums.size();i++) {
            //1.check if front element is out of bound then pop_front
            if(!q.empty() && q.front()<=i-k) {
                q.pop_front();
            }
            
            //2.if last element of queue is greater than ith element then pop_back
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            //3.if i>=k-1 then push queue front to ans vector
            if(i>=k-1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};