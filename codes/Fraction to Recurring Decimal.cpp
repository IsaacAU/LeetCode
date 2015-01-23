class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long num=numerator, denom=denominator;
        bool neg=false;
        if(num>0 && denom<0 || num<0 && denom>0)
            neg=true;
        num=abs(num);  denom=abs(denom);
        string res=to_string(num/denom);
        num%=denom;
        if(neg)
            res='-'+res;
        if(num==0)
            return res;
        res+='.';
        size_t pos=res.length();
        vector<int> rem;
        while(num){
            auto p=find(begin(rem), end(rem), num);
            if(p!=end(rem)){
                int dif=p-begin(rem);
                res.insert(pos+dif, 1, '(');
                res.push_back(')');
                break;
            }
            rem.push_back(num);
            num*=10;
            res+=to_string(num/denom);
            num%=denom;
        }
        return res;
    }
};
