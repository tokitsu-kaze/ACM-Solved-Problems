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
const int MAX=2e5+10;
const ll mod=1e9+7;
char s[2010][2010];
int main()
{
	int n,m,k,i,j,cnt,ans;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=0;i<n;i++) scanf("%s",s[i]);
		cnt=ans=0;
		for(i=0;i<n;i++)
		{
			int now=0;
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='.') now++,cnt++;
				else now=0;
				if(now>=k) ans++;
			}
		}
		for(j=0;j<m;j++)
		{
			int now=0;
			for(i=0;i<n;i++)
			{
				if(s[i][j]=='.') now++;
				else now=0;
				if(now>=k) ans++;
			}
		}
		if(k==1) printf("%d\n",cnt);
		else printf("%d\n",ans);
	}
	return 0;
}
/*
2 2 1
..
..
3 3 2
...
...
...
*/