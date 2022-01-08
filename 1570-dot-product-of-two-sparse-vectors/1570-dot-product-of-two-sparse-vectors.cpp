class SparseVector {
public:
    
    //1.store all nonzero values to map
    unordered_map<int,int> mp;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                mp[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(auto it=vec.mp.begin();it!=vec.mp.end();it++) {
            int key = it->first;
            if(mp.find(key) != mp.end()) {
                result += mp[key]*vec.mp[key];
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);