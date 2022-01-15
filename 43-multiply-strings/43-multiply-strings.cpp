class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0") return "0";
        int l1=num1.size();
        int l2=num2.size();
        vector<int> res(l1+l2,0);
        int i=l2-1;
        int pf=0;
        while(i>=0) {
            int ival = num2[i]-'0';
            int j = l1-1;
            int k = res.size()-1-pf;
            int carry=0;
            while(j>=0 || carry!=0) {
                int jval = j>=0 ? num1[j]-'0':0;
                int product = (ival * jval)+carry+res[k];
                res[k]=product%10;
                carry=product/10;
                
                k--;
                j--;
            }
            i--;
            pf++;
        }
        string ans="";
        int x=0;
        for(;x<res.size();x++) {
            if(res[x]!=0) break;
        }
        while(x<res.size()) {
            ans+=res[x]+'0';
            x++;
        }
        return ans;
    }
};