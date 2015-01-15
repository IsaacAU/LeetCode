class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1; i<=n; ++i)
            s.push_back('0'+i);
        string res;
        --k;
        while(k){
            int num=factor(--n);
            int d=k/num;
            res.push_back(s[d]);
            s.erase(d,1);
            k=k%num;
        }
        res+=s;
        return res;
    }
private:
    int factor(int n){
        int res=1;
        for(int i=1; i<=n; ++i)
            res*=i;
        return res;
    }
};
