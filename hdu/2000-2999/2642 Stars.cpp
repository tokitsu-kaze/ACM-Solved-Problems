////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-12 00:53:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2642
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:5664KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e3+10;
const ll mod=1e9+7;
struct Fenwick_Tree
{
	int bit[MAX][MAX];
	int n,m;
	void init(int _n,int _m){n=_n;m=_m;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void update(int x,int y,int v)
	{
		int i,j;
		for(i=x;i<=n;i+=lowbit(i))
		{
			for(j=y;j<=m;j+=lowbit(j))
			{
				bit[i][j]+=v;
			}
		} 
	}
	int getsum(int x,int y)
	{
		int i,j,res=0;
		for(i=x;i>0;i-=lowbit(i))
		{
			for(j=y;j>0;j-=lowbit(j))
			{
				res+=bit[i][j];
			}
		}
		return res;
	}
}t;
int main()
{
	int q,x1,x2,y1,y2,temp;
	char op[11];
	while(~scanf("%d",&q))
	{
		t.init(1001,1001);
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='B')
			{
				scanf("%d%d",&x2,&y2);
				x2++;
				y2++;
				x1=x2-1;
				y1=y2-1;
				temp=t.getsum(x2,y2)-t.getsum(x1,y2)-t.getsum(x2,y1)+t.getsum(x1,y1);
				if(!temp) t.update(x2,y2,1);
			}
			else if(op[0]=='D')
			{
				scanf("%d%d",&x2,&y2);
				x2++;
				y2++;
				x1=x2-1;
				y1=y2-1;
				temp=t.getsum(x2,y2)-t.getsum(x1,y2)-t.getsum(x2,y1)+t.getsum(x1,y1);
				if(temp) t.update(x2,y2,-1);
			}
			else
			{
				scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
				if(x1>x2) swap(x1,x2);
				if(y1>y2) swap(y1,y2);
				x2++;
				y2++;
				printf("%d\n",t.getsum(x2,y2)-t.getsum(x1,y2)-t.getsum(x2,y1)+t.getsum(x1,y1));
			}
		}
	}
	return 0;
}
