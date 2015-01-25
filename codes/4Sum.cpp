class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        if(num.size()<4)    return res;
        sort(begin(num), end(num));
        for(int i=0; i<num.size()-3; ++i){
            if(i>0 && num[i]==num[i-1]) continue;
            if(4*num[i]>target) break;
            for(int j=i+1; j<num.size()-2; ++j){
                if(j>i+1 && num[j]==num[j-1])   continue;
                if(3*num[j]>target-num[i])  break;
                int x=j+1, y=num.size()-1;
                while(x<y){
                    int sum=num[i]+num[j]+num[x]+num[y];
                    if(sum==target){
                        res.push_back({num[i], num[j], num[x], num[y]});
                        ++x;    --y;
                    }else if(sum>target)
                        --y;
                    else
                        ++x;
                    while(x>j+1 && x<num.size() && num[x]==num[x-1])    ++x;
                    while(y<num.size()-1 && y>j && num[y]==num[y+1])    --y;
                }
            }
        }
        return res;
    }
};
