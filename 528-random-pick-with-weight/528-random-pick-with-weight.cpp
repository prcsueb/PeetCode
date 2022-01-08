class Solution {
public:
    vector<int> psum;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i=0;i<w.size();i++) {
            sum += w[i];
            psum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int rand_weight = rand()%psum[psum.size()-1];
        return upper_bound(psum.begin(),psum.end(),rand_weight)-psum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */