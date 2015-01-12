class Solution {
public:
    string intToRoman(int num) {
        vector<int> v{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i=0;
        string res;
        while(num){
            int cnt=num/v[i];
            if(cnt){
                while(cnt--)
                    res+=s[i];
                num=num%v[i];
            }
            ++i;
        }
        return res;
    }
};
