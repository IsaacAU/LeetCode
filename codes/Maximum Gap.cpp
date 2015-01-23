class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2)    return 0;
        int min=INT_MAX, max=-1;
        for(auto i:num){
            if(i<min)   min=i;
            if(i>max)   max=i;
        }
        int len=(max-min)/num.size()+1;
        int sz=(max-min)/len+1;
        vector<int> minBucket(sz, -1);
        vector<int> maxBucket(sz, -1);
        for(auto x:num){
            int idx=(x-min)/len;
            if(minBucket[idx]<0 || minBucket[idx]>x)    minBucket[idx]=x;
            if(maxBucket[idx]<0 || maxBucket[idx]<x)    maxBucket[idx]=x;
        }
        int res=0, pre=0;
        for(int i=1; i<sz; ++i){
            if(minBucket[i]>=0){
                if(minBucket[i]-maxBucket[pre]>res) res=minBucket[i]-maxBucket[pre];
                pre=i;
            }
        }
        return res;
    }
};
