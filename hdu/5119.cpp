////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-10 22:05:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5119
////Problem Title: 
////Run result: Accept
////Run time:1419MS
////Run memory:67360KB
//////////////////System Comment End//////////////////
#include<bits/stdc++.h>
using namespace std;
const int MAX=1000005;
typedef long long ll;
int n,m;
struct trie
{
    int cnt[32*MAX];
    void insert(int x,int pos,int v)
    {
        if(pos<0)
        {
            cnt[x]++;
            return;
        }
        insert((x<<1)|((v>>pos)&1),pos-1,v);
        cnt[x]=cnt[x<<1]+cnt[x<<1|1];
    }
    void clear(int x,int pos)
    {
        cnt[x]=0;
        if(pos<0) return;
        clear(x<<1,pos-1);
        clear(x<<1|1,pos-1);
    }
    int query(int x,int pos,int v)
    {
        if(pos<0) return cnt[x];
        int tmp=(v>>pos)&1;
        int mm=(m>>pos)&1;
        int res=0;
        if(tmp)//v^x>=m
        {
            if(mm) res+=query((tmp|(x<<1))^1,pos-1,v);
            else res+=cnt[x<<1]+query((tmp|(x<<1)),pos-1,v);
        }
        else if(!tmp)
        {
            if(!mm) res+=cnt[x<<1|1]+query((tmp|(x<<1)),pos-1,v);
            else res+=query((tmp|(x<<1))^1,pos-1,v);
        }
        return res;
    }
}tr;
vector<int> a,b;
ll ans;
void dfs1(int pos,int now)
{
    if(pos==a.size())
    {
        tr.insert(1,22,now);
        return ;
    }
    dfs1(pos+1,now^a[pos]);
    dfs1(pos+1,now);
}
void dfs2(int pos,int now)
{
    if(pos==b.size())
    {
        ans+=tr.query(1,22,now);
        return ;
    }
    dfs2(pos+1,now^b[pos]);
    dfs2(pos+1,now);
}
int main()
{
    int t,x,i;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        tr.clear(1,22);
        scanf("%d%d",&n,&m);
        a.clear();
        b.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(i&1) a.push_back(x);
            else b.push_back(x);
        }
        ans=0;
        dfs1(0,0);
        dfs2(0,0);
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
/*
100
3 0
0 0 0
*/
