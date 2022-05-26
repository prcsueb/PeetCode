class Solution {
public:
    //logic : if a>=0 that means if we calclate equation for each element in nums and store it then last element will be the biggest one so in that case we start filling result array from last index as we are sure about biggest number
    //ex. [-4,-2,2,4], a = 1, b = 3, c = 5
    //calc[9,3,15,33] here 33 is biggest and its atend of the list
    // if a<0 that means after calculation of equation for each element in nums we can surely say that we will have smallest element at the first index so we start filling answer array from index 0
     //calc[-23,-5,7,1] here -23 is smallest and its at starting of the list
    int quadratic(int val ,int a, int b, int c) {
        return a*val*val+b*val+c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int l=0;
        int r=nums.size()-1;
        int i = a >= 0 ? r : 0;
        vector<int> res(nums.size(), 0);
        while(l <= r) {
            int leftQuad = quadratic(nums[l], a, b, c);
            int rightQuad = quadratic(nums[r], a, b, c);
            if(a >= 0) {    
                if(leftQuad >= rightQuad) {
                    res[i] = leftQuad;
                    l++;
                    i--;
                } else {
                    res[i] = rightQuad;
                    r--;
                    i--;
                }
            } else {
                if(leftQuad >= rightQuad) {
                    res[i] = rightQuad;
                    r--;
                    i++;
                } else {
                    res[i] = leftQuad;
                    l++;
                    i++;
                }
            }
        }
        return res;
    }
};