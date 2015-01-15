class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for(int i=0; i<s.length(); ++i){
            res=26*res+int(s[i]-'A'+1);
        }
        return res;
    }
};
