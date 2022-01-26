class Solution {
public:
    string binary="";
    void getB(int num) {
        while(num>0) {
            if(num%2==0) {
              binary="0"+binary;
            } else {
                binary="1"+binary;
            }
            num=num/2;
        }
    }
    string encode(int num) {
        getB(num+1);
        binary = binary.substr(1);
        return binary;
    }
};