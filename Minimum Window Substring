class Solution {
public:
    string minWindow(string S, string T) {
        int desire[256], cur[256];
        fill_n(desire, 256, 0);
        fill_n(cur, 256, 0);
        for(char c:T)
            desire[unsigned(c)]++;
        int start=0, end=0, bestStart=-1, bestEnd=S.length(), cnt=0;
        while(end<S.length()){
            int i=unsigned(S[end]);
            ++cur[i];
            if(cur[i]<=desire[i])   ++cnt;
            if(cnt==T.length()){
                while(desire[unsigned(S[start])]==0 || cur[unsigned(S[start])]>desire[unsigned(S[start])]){
                    if(cur[unsigned(S[start])]>desire[unsigned(S[start])])  --cur[unsigned(S[start])];
                    ++start;
                }
                if(bestStart<0 || end-start<bestEnd-bestStart){
                    bestStart=start;
                    bestEnd=end;
                }
                --cur[unsigned(S[start])]; ++start; --cnt;
            }
            ++end;
        }
        if(bestStart<0) return string();
        else    return S.substr(bestStart, bestEnd-bestStart+1);
    }
};
