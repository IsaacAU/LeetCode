class Solution {
public:
    int findMin(vector<int> &num) {
        int i=0, j=num.size()-1;
        while(i<=j){
            int m=(i+j)/2;
            if(num[i]<=num[m] && num[m]<=num[j])
                return num[i];
            else if(num[i]<=num[m] && num[m]>num[j])
                i=m+1;
            else if(num[i]>num[m] && num[m]<num[j])
                j=m;
        }
        return 0;
    }
};
