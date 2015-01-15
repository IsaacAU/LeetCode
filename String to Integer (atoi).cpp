class Solution {
public:
    int atoi(const char *str) {
        int res=0;
        while(*str!='\0' && isspace(*str))  ++str;
        if(*str=='\0')  return res;
        if(*str!='+' && *str!='-' && !isdigit(*str))    return res;
        bool neg=false;
        if(*str=='-')   neg=true;
        if(*str=='+' || *str=='-')  ++str;
        while(*str!='\0' && isdigit(*str)){
            if(res>INT_MAX/10)  return neg?INT_MIN:INT_MAX;
            if(!neg && res==INT_MAX/10 && int(*str-'0')>=INT_MAX%10)    return INT_MAX;
            if(neg && res==INT_MAX/10 && int(*str-'0')>INT_MAX%10)  return INT_MIN;
            res=10*res+int(*str-'0');
            ++str;
        }
        return neg?-res:res;
    }
};
