class Solution {
public:
    int findMin(vector<int> &num) {
        int i=0, j=num.size()-1;
        while(i<j){
            while(i<j && num[i]==num[i+1])  ++i;
            while(i<j && num[j-1]==num[j])  --j;
            int m=(i+j)/2;
            if(num[i]<=num[m] && num[m]<=num[j])
                return num[i];
            else if(num[i]<=num[m] && num[m]>num[j])
                i=m+1;
            else
                j=m;
        }
        return num[i];
    }
};
