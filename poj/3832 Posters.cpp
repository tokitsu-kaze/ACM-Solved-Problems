#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
  
#define  lz  2*u,l,mid  
#define  rz  2*u+1,mid+1,r  
const int maxn=50005;  
typedef long long lld;  
lld sum[4*maxn];  
int flag[4*maxn];  
  
struct Node  
{  
    int lx, rx, h, s;  
    Node(){}  
    Node(int lx_, int rx_, int h_, int s_)  
    {  
        lx=lx_, rx=rx_, h=h_, s=s_;  
    }  
    bool operator<(const Node &S)const  
    {  
        return h<S.h;  
    }  
}line[8*maxn];  
  
void push_up(int u, int l, int r)  
{  
    if(flag[u]) sum[u]=r-l+1;  
    else if(l==r) sum[u]=0;  
    else sum[u]=sum[2*u]+sum[2*u+1];  
}  
  
void Update(int u, int l, int r, int tl, int tr, int c)  
{  
    if(tl>tr) return ;  ///!!!注意 当x1==x2时，会导致RE，因为算区间的时候x2会减-1  
    if(tl<=l&&r<=tr)  
    {  
        flag[u]+=c;  
        push_up(u,l,r);  
        return ;  
    }  
    int mid=(l+r)>>1;  
    if(tr<=mid) Update(lz,tl,tr,c);  
    else if(tl>mid) Update(rz,tl,tr,c);  
    else  
    {  
        Update(lz,tl,mid,c);  
        Update(rz,mid+1,tr,c);  
    }  
    push_up(u,l,r);  
}  
  
int main()  
{  
    int n;  
    while(cin >> n,n)  
    {  
        memset(flag,0,sizeof(flag));  
        memset(sum,0,sizeof(sum));  
        int num=0;  
        int x1, y1, x2, y2, x3, y3, x4, y4;  
        int lbd=maxn, rbd=-1;  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x4,&y4,&x2,&y2,&x3,&y3);  
            line[++num]=Node(x1,x4,y1,1);  
            line[++num]=Node(x1,x4,y2,-1);  
            line[++num]=Node(x1,x4,y3,1);  
            line[++num]=Node(x1,x4,y4,-1);  
            line[++num]=Node(x1,x2,y2,1);  
            line[++num]=Node(x1,x2,y3,-1);  
            line[++num]=Node(x3,x4,y2,1);  
            line[++num]=Node(x3,x4,y3,-1);  
            lbd=min(x1,lbd);  
            rbd=max(x4,rbd);  
        }  
        sort(line+1,line+num+1);  
        lld ans=0;  
        for(int i=1; i<num; i++)  
        {  
            Update(1,lbd,rbd,line[i].lx,line[i].rx-1,line[i].s);  
            ans+=sum[1]*(lld)(line[i+1].h-line[i].h);  
        }  
        cout << ans <<endl;  
    }  
    return 0;  
} 
