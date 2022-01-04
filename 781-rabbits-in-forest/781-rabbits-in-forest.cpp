class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> groups;
        for(int i=0;i<answers.size();i++) {
            groups[answers[i]]++;
        }
        
        int ans = 0;
        for(auto it=groups.begin();it!=groups.end();it++) {
            int groupSize = it->first+1;
            int total = it->second;
            int totalOfSameColor = total / groupSize;
            if(total % groupSize != 0) {
                totalOfSameColor ++;
            }
            ans += totalOfSameColor * groupSize;
        }
        
        return ans;
    }
};