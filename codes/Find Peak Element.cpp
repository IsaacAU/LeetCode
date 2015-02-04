// O(n) solution
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

// O(logn) solution (Binary search)
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int i=0, j=num.size()-1;
        while(i<j){
            int m=(i+j)/2;
            if(m==num.size()-1 || num[m]>num[m+1])
                j=m;
            else
                i=m+1;
        }
        return i;
    }
};
