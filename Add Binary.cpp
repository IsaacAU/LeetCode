class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        int la=a.length(), lb=b.length();
        int lr=max(la,lb);
        string res(lr, '0');
        int c=0;
        for(int i=0; i<lr; ++i){
            int xa=0, xb=0;
            if(i<la && a[i]=='1')   xa=1;
            if(i<lb && b[i]=='1')   xb=1;
            res[i]=(xa+xb+c)%2+'0';
            c=(xa+xb+c)/2;
        }
        if(c)   res+='1';
        reverse(begin(res), end(res));
        return move(res);
    }
};
