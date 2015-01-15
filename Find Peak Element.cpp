class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int idx=0;
        while(idx<num.size()-1){
            if((idx==0 || num[idx]>num[idx-1]) && num[idx]>num[idx+1])
                break;
            ++idx;
        }
        return idx;
    }
};
