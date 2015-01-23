class Solution {
public:
    string longestPalindrome(string s) {
        const int len=s.length();
        bool palin[len][len];
        int length=1, start=0;
        for(int i=len-1; i>=0; --i){
            palin[i][i]=true;
            for(int j=i+1; j<len; ++j){
                palin[i][j]=(j<i+3 || palin[i+1][j-1])&&s[i]==s[j];
                if(palin[i][j] && j-i+1>length){
                    start=i;
                    length=j-i+1;
                }
            }
        }
        return s.substr(start, length);
    }
};
