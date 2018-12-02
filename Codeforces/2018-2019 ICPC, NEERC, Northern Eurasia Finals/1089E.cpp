#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
string s1="abcdefgh";
string s2="12345678";
vector<pair<int,int>> ans;
int main() {
    int n;scanf("%d",&n);

    int r = n%16;
    int k = n/16;
    int y = 0;
    if(!k) ans.emplace_back(1,1);
    rep(i,1,k-1) {
        y++; rep(x,1,8) ans.emplace_back(x,y);
        y++; per(x,8,1) ans.emplace_back(x,y);
    }
    if(k) { y++; rep(x,1,8) ans.emplace_back(x,y); }
    if(!k) r--;
    if(r==0) {
        if(k) { y++; per(x,8,2) ans.emplace_back(x,y); }
        ans.emplace_back(2,8);
    } else {
        if(k) { y++; per(x,8,1) ans.emplace_back(x,y); }
        if( r==1 ) {
            ans.emplace_back(1,8);
        } else if( r<=8 ) {
            rep(i,1,r-1) ans.emplace_back(i,7);
            ans.emplace_back(r-1,8);
        }
        else if( r <= 14 ) {
            rep(i,1,7) ans.emplace_back(i,7);
            r -= 7;
            per(i,7,7-r+1) ans.emplace_back(i,8);
        } else {
            rep(i,1,6) ans.emplace_back(i,7);
            ans.emplace_back(8,7);
            ans.emplace_back(7,7);
            per(i,7,1) ans.emplace_back(i,8);
        }
    }
    ans.emplace_back(8,8);
    //cout<<((ans.size()==n+1)?"Y":"N") << endl;
    printf("a1");
    for(int i=1;i<ans.size();++i) {
        auto p = ans[i];
        printf(" %c%c",s1[p.first-1],s2[p.second-1]);
    }
    puts("");
    return 0;
}