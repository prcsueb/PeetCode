class Solution {
public:
    vector<int> csum;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i=0;i<w.size();i++) {
            sum += w[i];
            csum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int randomNumber = rand()%csum[csum.size()-1];
        return upper_bound(csum.begin(),csum.end(),randomNumber)-csum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */