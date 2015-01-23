class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if(num.size()<3)    return res;
        sort(begin(num), end(num));
        for(int i=0; i<num.size(); ++i){
            if(i>0 && num[i]==num[i-1]) continue;
            int target=-num[i];
            if(target<0)    break;
            int j=i+1, k=num.size()-1;
            while(j<k){
                if(num[j]+num[k]<target)
                    ++j;
                else if(num[j]+num[k]>target)
                    --k;
                else{
                    res.push_back(move(vector<int>{num[i],num[j],num[k]}));
                    ++j;
                    --k;
                }
                while(j>i+1 && num[j]==num[j-1]) ++j;
                while(k<num.size()-1 && num[k]==num[k+1]) --k;
            }
        }
        return move(res);
    }
};
