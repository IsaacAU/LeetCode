class Solution {
public:
    int totalNQueens(int n) {
        vector<int> v(n,0);
        int res=0, i=0;
        while(1){
            if(valid(v,i)){
                if(i==n-1){
                    ++res;
                    v[i]=0;
                    while(i>0 && v[--i]==n-1)   v[i]=0;
                    if(i==0 && v[i]==n-1)   break;
                    ++v[i];
                }else
                    ++i;
            }else{
                while(i>=0 && v[i]==n-1){ v[i]=0; --i; }
                if(i<0)   break;
                ++v[i];
            }
        }
        return res;
    }
private:
    bool valid(vector<int> &v, int i){
        for(int j=0; j<i; ++j){
            if(v[j]==v[i] || abs(i-j)==abs(v[i]-v[j]))
                return false;
        }
        return true;
    }
};
