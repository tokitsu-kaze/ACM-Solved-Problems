////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-25 17:46:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6034
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:13524KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
    char x;
    int p[MAX];
    int k,tag;
    friend bool operator<(const node &a,const node &b)
    {
        if(a.k==b.k)
        {
            for(int i=a.k;i>=0;i--)
            {
                    
                if(a.p[i]==b.p[i]) continue;
                else return a.p[i]>b.p[i];
            }
            return a.x>b.x;
        }
        else return a.k>b.k;
    }
}mp[26];
char a[MAX];
int main()
{
    int n,i,j,k,id,len,cas=1,cnt;
    ll ans,temp;
    while(~scanf("%d",&n))
    {
        for(i=0;i<26;i++)
        {
            mp[i].k=-1;
            mp[i].x='a'+i;
            mem(mp[i].p,0);
            mp[i].tag=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            len=strlen(a);
            for(j=len-1,k=0;j>=0;j--,k++)
            {
                if(j==0) mp[a[j]-'a'].tag=1;
                mp[a[j]-'a'].p[k]++;
                mp[a[j]-'a'].k=max(mp[a[j]-'a'].k,k);
                int pos=k;
                while(mp[a[j]-'a'].p[pos]>=26)
                {
                    mp[a[j]-'a'].p[pos+1]+=mp[a[j]-'a'].p[pos]/26;
                    mp[a[j]-'a'].p[pos]%=26;
                    pos++;
                    mp[a[j]-'a'].k=max(mp[a[j]-'a'].k,pos);
                }
            }
        }
        sort(mp,mp+26);
        cnt=0;
        for(i=0;i<26;i++)
        {
            if(mp[i].k!=-1) cnt++;
        }
        if(cnt==26&&mp[25].tag!=0)
        {
            node t=mp[25];
            for(i=24;i>=0;i--)
            {
                swap(t,mp[i]);
                if(t.tag==0) break;
            }
            mp[25]=t;
        }
        ans=0;
        for(i=25,id=0;i>=0;i--,id++)
        {
            if(mp[id].k==-1) break;
            temp=1;
    //        cout<<mp[id].x<<" ";
            for(j=0;j<=mp[id].k;j++)
            {
    //            cout<<mp[id].p[j];
                ans+=temp*(ll)i*mp[id].p[j];
                ans%=mod;
                temp*=26;
                temp%=mod;
            }
    //        puts("");
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
/*
26
abcd
cde
def
efg
fgh
hib
ijb
jkl
klm
lmn
mno
opq
pqr
qrs
rst
stu
tuv
uvw
vwx
xyz
yzb
zbb
ghi
nop
wxy
ddd
26
cbad
cde
def
efg
fgh
hib
ijb
jkl
klm
lmn
mno
opq
pqr
qrs
rst
stu
tuv
uvw
vwx
xyz
yzb
zbb
ghi
nop
wxy
ddd
*/