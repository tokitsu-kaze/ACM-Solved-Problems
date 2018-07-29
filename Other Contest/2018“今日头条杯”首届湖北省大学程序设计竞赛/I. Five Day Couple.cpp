#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+100;

struct Trie{
    int ch[2],sum,dep;
}T[N*32];
int root[N],sz;

void insert(int &i,int d,int x,int v){
    T[++sz]=T[i],i=sz;
    T[i].dep=d+1;
    T[i].sum+=v;    //此时判断的是上一位的d
    if(d<0) return ;
    int p=(x>>d)&1;
    insert(T[i].ch[p],d-1,x,v);
}

void Query_max_xor(int L,int R,int d,int x,int &ans){
    if(d<0)     return ;
    int p=(x>>d)&1;
    if(T[ T[R].ch[p^1] ].sum-T[ T[L].ch[p^1] ].sum)
        ans+=(p^1)*(1<<d),Query_max_xor(T[L].ch[p^1],T[R].ch[p^1],d-1,x,ans);
    else    ans+=p*(1<<d),Query_max_xor(T[L].ch[p],T[R].ch[p],d-1,x,ans);
}

void Query_equal_to_x(int L,int R,int d,int x,int &ans){
    if(d<0)     {ans+=T[R].sum-T[L].sum;return ;}
    int p=(x>>d)&1;
    if(p==1)  ans+=T[ T[R].ch[0] ].sum-T[ T[L].ch[0] ].sum;
    Query_equal_to_x(T[L].ch[p],T[R].ch[p],d-1,x-p*(1<<d),ans);
}

void Query_kth(int L,int R,int d,int x,int &ans){
    if(d<0)     return ;
    int k=T[ T[R].ch[0] ].sum-T[ T[L].ch[0] ].sum;
    if(k>=x)    Query_kth(T[L].ch[0],T[R].ch[0],d-1,x,ans);
    else   ans+=(1<<d),Query_kth(T[L].ch[1],T[R].ch[1],d-1,x-k,ans);
}

int main(){
    int i,m,n=0,L,R,ans,op,x;
    while(scanf("%d",&n)!=EOF)
	{
        sz=0,root[0]=0;
        for(i=1;i<=n;i++)
        {
			scanf("%d",&x);
            root[i]=root[i-1];
            insert(root[i],30,x,1);
		}
		scanf("%d",&m);
        while(m--)
		{
			scanf("%d%d%d",&x,&L,&R);
			Query_max_xor(root[L-1],root[R],30,x,ans=0);
			printf("%d\n",x^ans);
        }
    }
    return 0;
}