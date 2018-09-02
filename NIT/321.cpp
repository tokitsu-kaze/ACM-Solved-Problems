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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
char mp[222][222];
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t=100,n,m,i,j,x;
	printf("%d\n",t);
	t--;
	mem(mp,'.');
	n=m=200;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) putchar('.');
		puts("");
	}
	while(t--)
	{
		n=rand()%200+1;
		m=rand()%200+1;
		printf("%d %d\n",n,m);
		x=min(rand()%(n*m),(m*n/10));
		mem(mp,'.');
		while(x--)
		{
			i=1;
			j=1;
			while((i==1&&j==1)||(i==n&&j==m))
			{
				i=rand()%n+1;
				j=rand()%m+1;
			}
			mp[i][j]='X';
		}
		x=rand()%4;
		if(x)
		{
			x=2;
			while(x--)
			{
				be:;
				i=1;
				j=1;
				while(i==1&&j==1)
				{
					i=rand()%n+1;
					j=rand()%m+1;
				}
				if(mp[i][j]=='*') goto be;
				mp[i][j]='*';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) putchar(mp[i][j]);
			puts("");
		}
		if(t==2) break;
	}
	return 0;
}
*/
ll dp[222][222];
char mp[222][222];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,n,m,i,j;
	ll temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		mem(dp,0);
		temp=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(i==1&&j==1)
				{
					dp[1][1]=1;
					continue;
				}
				if(mp[i][j]=='X')
				{
					dp[i][j]=0;
					continue;
				}
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
				dp[i][j]%=mod;
				if(mp[i][j]=='*')
				{
					if(temp==-1)
					{
						temp=dp[i][j];
						dp[i][j]=0;
					}
					else
					{
						dp[i][j]+=temp;
						dp[i][j]%=mod;
					}
				}
				
			}
		}
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}
/*
2
4 4
....
XXX.
XXX.
XXX.
2 4
.*XX
XX*.
*/