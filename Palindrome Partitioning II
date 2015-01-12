class Solution {
public:
    int minCut(string s) {
        int len=s.length();
        bool palin[len][len];
        fill_n(*palin, len*len, false);
        int cnt[len];
        for(int i=len-1; i>=0; --i){
            cnt[i]=(i==len-1)?0:1+cnt[i+1];
            for(int j=i+1; j<len; ++j){
                palin[i][j]=(j<=i+2 || palin[i+1][j-1]) && s[i]==s[j];
                if(palin[i][j]) cnt[i]=min(cnt[i], (j==len-1)?0:1+cnt[j+1]);
            }
        }
        return cnt[0];
    }
};
