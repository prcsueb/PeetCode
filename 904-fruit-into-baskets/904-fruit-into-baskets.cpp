class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> mp;
        int i=-1;
        int j=-1;
        int ans = INT_MIN;
        while(i<n-1) {
            while(i<n-1 && mp.size()<=2) {
                ++i;
                mp[fruits[i]]++;
                if(mp.size()<=2) {
                    ans = max(ans,i-j);
                }
            }
            while(j<i) {
                ++j;
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0) {
                    mp.erase(mp.find(fruits[j]));
                }
                if(mp.size()<=2) {
                    ans=max(ans,i-j);break;
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};