class Solution {
public:
    string convertToTitle(int n) {
        string res;
        --n;
        while(n>=0){
            res=char(n%26+'A')+res;
            n=n/26-1;
        }
        return res;
    }
};
