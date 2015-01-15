class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;
        int i=0, j=1;
        bool arr[256];
        fill_n(arr, 256, false);
        arr[unsigned(s[0])]=true;
        int res=1;
        while(j<s.length()){
            if(arr[unsigned(s[j])]){
                while(s[i]!=s[j]){
                    arr[unsigned(s[i])]=false;
                    ++i;
                }
                ++i;
            }else
                arr[unsigned(s[j])]=true;
            res=max(res, j-i+1);
            ++j;
        }
        return res;
    }
};
