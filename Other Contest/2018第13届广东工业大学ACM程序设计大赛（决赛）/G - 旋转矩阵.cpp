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
int main()
{
	int t,n,m,i,j,len,now;
	char s[1111],mp[33][33],ans[33][33];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
		}
		scanf("%s",s);
		len=strlen(s);
		now=1;
		for(i=0;i<len;i++)
		{
			if(s[i]=='L') now--;
			else now++;
			now%=4;
			if(now==0) now=4;
		}
		mem(ans,0);
		if(now==1)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					ans[i][j]=mp[i][j];
				}
			}
		}
		else if(now==2)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					ans[j][n-i-1]=mp[i][j];
					if(ans[j][n-i-1]=='-') ans[j][n-i-1]='|';
					else if(ans[j][n-i-1]=='|') ans[j][n-i-1]='-';
				}
			}
			swap(n,m);
		}
		else if(now==3)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					ans[n-i-1][m-j-1]=mp[i][j];
				}
			}
		}
		else if(now==4)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					ans[m-j-1][i]=mp[i][j];
					if(ans[m-j-1][i]=='-') ans[m-j-1][i]='|';
					else if(ans[m-j-1][i]=='|') ans[m-j-1][i]='-';
				}
			}
			swap(n,m);
		}
		printf("%d %d\n",n,m);
		for(i=0;i<n;i++) puts(ans[i]);
		puts("");
	}
	return 0;
}
