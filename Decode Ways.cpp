class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0')  return 0;
        vector<int> v(s.length(), 0);
        v[0]=1;
        for(int i=1; i<s.length(); ++i){
            if(s[i]=='0'){
                if(s[i-1]>'2' || s[i-1]=='0')
                    return 0;
                else
                    v[i]=i>1?v[i-2]:1;
            }else{
                v[i]=v[i-1];
                if(s[i-1]=='1' || s[i-1]=='2' && s[i]<='6')
                    v[i]+=i>1?v[i-2]:1;
            }
        }
        return v.back();
    }
};
