class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        assert(!num.empty());
        sort(begin(num), end(num));
        int res=0, dif=INT_MAX;
        for(int i=0; i<num.size(); ++i){
            int j=i+1, k=num.size()-1;
            while(j<k){
                int sum=num[i]+num[j]+num[k];
                if(abs(sum-target)<dif){
                    res=sum;
                    dif=abs(sum-target);
                }
                if(sum>target)
                    --k;
                else if(sum<target)
                    ++j;
                else
                    return sum;
            }
        }
        return res;
    }
};
