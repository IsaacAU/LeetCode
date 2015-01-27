bool isOneEditDistance(string s, string t){
    if(s.length()>t.length())   return isOneEditDistance(t, s);
    const int m=s.length(), n=t.length();
    if(n-m>1)   return false;
    int i=0;
    for(; i<m; ++i)
        if(s[i]!=t[i])
            break;
    if(i==m)    return n>m;
    for(; i<m; ++i)
        if(s[i]!=t[i+1])
            break;
    return i==m;
}
