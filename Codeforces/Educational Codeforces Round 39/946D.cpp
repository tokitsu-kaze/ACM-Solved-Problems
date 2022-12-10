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
const int MAX=1e5+10;
const ll mod=1e9+7;
int dp[505][505],cost[505][505];
int main()
{
	int n,m,k,i,j,l,bit[505],cnt,tmp;
	char s[505];
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			mem(bit,0);
			cnt=0;
			for(j=1;j<=m;j++)
			{
				if(s[j]=='1')
				{
					bit[j]=1;
					cnt++;
				}
				bit[j]+=bit[j-1];
			}
			mem(cost[i],0x3f);
			cost[i][cnt]=0;
			for(j=1;j<=m;j++)
			{
				for(l=j;l<=m;l++)
				{
					tmp=cnt-(bit[l]-bit[j-1]);
					if(tmp==cnt) cost[i][tmp]=0;
					else cost[i][tmp]=min(cost[i][tmp],l-j+1);
				}
			}
	/*		for(j=0;j<=k;j++)
			{
				cout<<cost[i][j]<<endl;
			}*/
		}
		mem(dp[0],0);
		for(i=1;i<=n;i++)
		{
			mem(dp[i],0x3f);
			for(j=0;j<=k;j++)
			{
				for(l=0;l<=j;l++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-l]+cost[i][l]);
				}
			}
		}
		printf("%d\n",dp[n][k]);
	}
	return 0;
}