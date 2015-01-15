class Solution {
public:
    // recursion: Time Limit Exceeded!!!!!!!
    bool isMatch1(const char *s, const char *p) {
        if(*s=='\0')
            return *p=='\0' || *p=='*' && isMatch(s, p+1);
        if(*p=='\0')    return false;
        if(*s==*p || *p=='?')   return isMatch(s+1, p+1);
        if(*p=='*') return isMatch(s+1, p) || isMatch(s+1, p+1);
    }
    // iterative
    bool isMatch2(const char *s, const char *p) {
        const char *starS=nullptr, *starP=nullptr;
        while(*s){
            if(*s==*p || *p=='?'){
                ++s;  ++p;
            }else if(*p=='*'){
                while(*p=='*')  ++p;
                starP=p;
                starS=s;
            }else if(starP && *starS){
                p=starP;
                s=++starS;
            }else
                return false;
        }
        while(*p=='*')  ++p;
        return *p=='\0';
    }
};
