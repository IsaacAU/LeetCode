class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int num=0, res=0;
        while(*s){
            if(!isspace(*s))    
                ++num;
            else{
                if(num>0)   res=num;
                num=0;
            }
            ++s;
        }
        return num==0?res:num;
    }
};
