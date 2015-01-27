#include<iostream>
#include<cstdio>

using namespace std;

class Solution{
public:
    Solution(const char *file){
        freopen(file, "r", stdin);
        cin.sync_with_stdio(0);
        cin.tie(0);
        cur=0;
    }
    int read(char *buf, int n){
        int i=0;
        if(cur!=0){
            while(i<n && cur<4)
                buf[i++]=backup[cur++];
            if(cur==4)  cur=0;
            if(i==n)    return n;
        }
        buf=buf+i;
        int k=(n-i)/4, j=0, x;
        for(; j<k; ++j){
            x=read4(buf+4*j);
            if(x<4) return i+4*j+x;
        }
        if((n-i)%4==0)  return i+4*j;
        x=read4(backup);
        for(; cur<min(x,(n-i)%4); ++cur)
            buf[4*j+cur]=backup[cur];
        return i+4*j+min(x,(n-i)%4);
    }
    int read4(char *buf){
        int n=0;
        while(cin.get(buf[n]) && ++n<4);
        return n;
    }
private:
    char backup[4];
    int cur;
};

int main(){
    Solution s("input.txt");
    int n=10, x;
    char *buf=new char[n];
    for(int i=1; i<=10; ++i){
        x=s.read(buf, i);
        cout<<x<<endl;
        cout<<buf<<endl;
    }
    delete []buf;
}
