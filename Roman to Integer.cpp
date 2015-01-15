class Solution {
public:
    int romanToInt(string s) {
        vector<string> lib{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> num{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i=0, j=0;
        int res=0;
        while(i<s.length()){
            while(s.substr(i,1)!=lib[j] && (i==s.length()-1 || s.substr(i,2)!=lib[j]))
                ++j;
            res+=num[j];
            i+=lib[j].length();
        }
        return res;
    }
};
