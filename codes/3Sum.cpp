class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if(num.size()<3)    return res;
        sort(begin(num), end(num));
        for(int i=0; i<num.size()-2; ++i){
            if(i>0 && num[i]==num[i-1]) continue;
            if(num[i]>0)    break;
            int x=i+1, y=num.size()-1;
            while(x<y){
                int sum=num[i]+num[x]+num[y];
                if(sum==0){
                    res.push_back({num[i], num[x], num[y]});
                    ++x;    --y;
                }else if(sum>0)
                    --y;
                else
                    ++x;
                while(x>i+1 && x<num.size() && num[x]==num[x-1])    ++x;
                while(y<num.size()-1 && y>i && num[y]==num[y+1])    --y;
            }
        }
        return res;
    }
};
