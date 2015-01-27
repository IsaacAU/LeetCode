int lengthOfLongestSubstringTwoDistinct(string s){
    const int len=s.length();
    if(len<3)   return len;
    int i=1;
    while(i<len && s[i]==s[i-1])    ++i;
    if(i==len)  return len;
    int start=0, next=i++;
    char c=s[next];
    int res=next+1;
    for(; i<len; ++i){
        if(s[i]==s[i-1])
        else if(s[i]==s[start] || s[i]==c)
            next=i;
        else{
            start=next;
            next=i;
            c=s[i];
        }
        res=max(res, i-start+1);
    }
    return res;
}
