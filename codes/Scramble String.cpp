class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)  return true;
        int arr[26];
        fill_n(arr, 26, 0);
        for(auto c:s1)  arr[unsigned(c-'a')]++;
        for(auto c:s2)  arr[unsigned(c-'a')]--;
        for(int i=0; i<26; ++i)    if(arr[i])  return false;
        int len=s1.length();
        if(len<3)   return true;
        for(int i=1; i<len; ++i){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,len-i), s2.substr(i,len-i)) ||
               isScramble(s1.substr(0,i), s2.substr(len-i,i)) && isScramble(s1.substr(i,len-i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
