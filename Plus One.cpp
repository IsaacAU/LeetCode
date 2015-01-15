class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c=1, i=digits.size()-1;
        while(c && i>=0){
            int x=(digits[i]+c)%10;
            c=(digits[i]+c)/10;
            digits[i]=x;
            --i;
        }
        if(c)
            digits.insert(begin(digits), 1);
        return digits;
    }
};
