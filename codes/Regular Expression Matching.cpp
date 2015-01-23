class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*s=='\0')
            return *p=='\0' || *(p+1)=='*' && isMatch(s, p+2);
        if(*p=='\0')
            return false;
        if(*(p+1)=='*'){
            return isMatch(s, p+2) || (*s==*p || *p=='.') && isMatch(s+1,p);
        }else
            return (*s==*p || *p=='.') && isMatch(s+1, p+1);
    }
};
