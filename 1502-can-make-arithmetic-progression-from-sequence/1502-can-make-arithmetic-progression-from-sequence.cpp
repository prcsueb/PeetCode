class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        set<int> st;
        int minn = INT_MAX;
        int sminn = INT_MAX;
        
        for(int i=0;i<arr.size();i++) {
            if(arr[i] < minn) {
                sminn = minn;
                minn = arr[i];
            } else if(arr[i] < sminn) {
                sminn = arr[i];
            }    
            st.insert(arr[i]);
        }
        
        int cd = sminn - minn;
        
        //if common diff is 0 that means all the elements are same
        //so hashset ni size 1 hovi joye, but jo > 1 ave to badha same element nathi and ap na mde
        if(cd == 0 && st.size() > 1) {
            return false;
        }
        
        for(int i=0;i<arr.size();i++) {
            int term = i * cd + minn;
            if(st.find(term) == st.end()) {
                return false;
            }
        }
        
        return true;
    }
};