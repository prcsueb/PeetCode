class Solution {
public:
    int getGcd(int a, int b)
    {
        if(a==0) return b;
        return getGcd(b%a, a);
    }
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len < 3) {
            return len;
        }
        int res = 0; //compute result
        for(int i=0;i+res<len;i++) {
            int dupl = 0; //it stores max values overlaps
            int maxV = 0; //it store max value in each map entry
            int v=0;
            unordered_map<string, int> mp;
            int x1=points[i][0], y1=points[i][1];
            for(int j=i+1;j<len;j++) {
                int x2=points[j][0];
                int y2=points[j][1];
                int dx=(x2-x1);
                int dy=(y2-y1);
                if(dx==0 && dy==0) {
                    dupl++;
                } else {
                    int gcd = getGcd(dx,dy);
                    if(gcd!=0) {
                        dx/=gcd;
                        dy/=gcd;
                    }
                    string key = to_string(dx)+'/'+to_string(dy);
                    ++mp[key];
                    v=mp[key];
                }
                maxV=max(maxV,v);
                res=max(res, maxV+dupl+1);
            }
        }
        return res;
    }
};