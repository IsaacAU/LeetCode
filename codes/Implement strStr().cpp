class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1=strlen(haystack), len2=strlen(needle);
        if(len2>len1)   return -1;
        if(len2==0) return 0;
        for(int i=0; i<=len1-len2; ++i){
            bool find=true;
            for(int j=0; j<len2; ++j){
                if(haystack[i+j]!=needle[j]){
                    find=false;
                    break;
                }
            }
            if(find)    return i;
        }
        return -1;
    }
};
