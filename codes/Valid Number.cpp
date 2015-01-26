class Solution {
public:
    bool isNumber(const char *s) {
        while(isspace(*s))  ++s;
        if(*s=='+' || *s=='-')  ++s;
        int npt=0, ndig=0;
        while(isdigit(*s) || *s=='.'){
            if(*s=='.') ++npt;
            else    ++ndig;
            ++s;
        }
        if(npt>1 || ndig<1) return false;
        if(*s=='e' ||*s=='E'){
            ++s;
            if(*s=='+' || *s=='-') ++s;
            int ndig=0;
            while(isdigit(*s)){
                ++ndig;
                ++s;
            }
            if(ndig<1)  return false;
        }
        while(isspace(*s))  ++s;
        return *s=='\0';
    }
};
