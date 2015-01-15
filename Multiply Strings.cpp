class Solution {
public:
    string multiply(string num1, string num2) {
        int len=num1.length();
        string res=oneDigit(num2+string(len-1,'0'), num1[0]-'0');
        for(int i=1; i<len; ++i){
            res=add(res, oneDigit(num2+string(len-i-1, '0'), num1[i]-'0'));
        }
        return res;
    }
private:
    string oneDigit(string num1, int d){
        int c=0;
        string res(num1.length(),'0');
        for(int i=num1.length()-1; i>=0; --i){
            int x=d*(num1[i]-'0')+c;
            res[i]=x%10+'0';
            c=x/10;
        }
        if(c>0)
            res=char(c+'0')+res;
        while(res[0]=='0' && res.length()>1)  res.erase(0,1);
        return res;
    }
    string add(string num1, string num2){
        int c=0;
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        string res(max(num1.length(), num2.length()), '0');
        for(int i=0; i<max(num1.length(), num2.length()); ++i){
            int x1=0, x2=0;
            if(i<num1.length()) x1=int(num1[i]-'0');
            if(i<num2.length()) x2=int(num2[i]-'0');
            res[i]=char((x1+x2+c)%10+'0');
            c=(x1+x2+c)/10;
        }
        if(c>0)
            res+='1';
        reverse(begin(res), end(res));
        return res;
    }
};
