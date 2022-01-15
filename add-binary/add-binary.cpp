class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int i=alen-1;
        int j=blen-1;
        string ans="";
        int carry=0;
        while(i>=0 || j>=0) {
            int aval=0;
            int bval=0;
            if(i>=0) {
                aval=a[i]-'0';
            }
            if(j>=0) {
                bval=b[j]-'0';
            }
            cout << aval << ", " << bval + "\n";
            int sum = aval+bval+carry;
            if(sum == 3) {
                // ans+='1';
                ans='1'+ans;
                carry=1;
            } else if(sum == 2) {
                // ans+='0';
                ans='0'+ans;
                carry=1;
            } else if(sum == 1) {
                // ans+='1';
                ans='1'+ans;
                carry=0;
            } else if(sum==0) {
                // ans+='0';
                ans='0'+ans;
                carry=0;
            }
            i--;
            j--;
        }
        if(carry!=0) {
            ans='1'+ans;
        }
        return ans;
    }
};