#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=1e5+10;
const ll mod=1e9+7;
double a[MAX];
int n,mp[15][15];
void dfs(int x,double v,int h,int tmp)
{
	if(h>n) return;
	if(v<=0) return;
	a[x]+=v;
	dfs(mp[h+1][tmp],(a[x]-1)/2,h+1,tmp);
	dfs(mp[h+1][tmp+1],(a[x]-1)/2,h+1,tmp+1);
	a[x]=min(a[x],1.0);
}
int main()
{
	int i,j,ans,t,tot;
	while(~scanf("%d%d",&n,&t))
	{
		tot=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				mp[i][j]=++tot;
			}
		}
		for(i=1;i<=tot;i++) a[i]=0;
		for(i=1;i<=t;i++) dfs(1,1,1,1);
		ans=0;
		for(i=1;i<=tot;i++) ans+=(a[i]==1);
		printf("%d\n",ans);
	}
	return 0;
}