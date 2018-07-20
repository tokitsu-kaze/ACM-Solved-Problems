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
const double eps=1e-8;
const int MAX=5e3+10;
const ll mod=1e9+7;
struct node
{
	int op,x,v;
	void input()
	{
		scanf("%d%d%d",&op,&x,&v);
	}
}a[100010];
int mp[MAX][MAX],r[MAX],c[MAX];
int main()
{
	int n,m,k,i,j;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(r,0);
		mem(c,0);
		mem(mp,0);
		for(i=0;i<k;i++)
		{
			a[i].input();
		}
		for(i=k-1;~i;i--)
		{
			if(a[i].op==1)
			{
				if(r[a[i].x]) continue;
				r[a[i].x]=1;
				for(j=1;j<=m;j++)
				{
					if(!mp[a[i].x][j]) mp[a[i].x][j]=a[i].v;
				}
			}
			else
			{
				if(c[a[i].x]) continue;
				c[a[i].x]=1;
				for(j=1;j<=n;j++)
				{
					if(!mp[j][a[i].x]) mp[j][a[i].x]=a[i].v;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%d",mp[i][1]);
			for(j=2;j<=m;j++)
			{
				printf(" %d",mp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}