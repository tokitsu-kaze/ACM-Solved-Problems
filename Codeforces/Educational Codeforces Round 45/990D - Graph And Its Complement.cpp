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
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int mp[1010][1010];
void work(int a,int b,int n)
{
	int i;
	for(i=0;i<n-a;i++)
	{
		mp[i][i+1]=mp[i+1][i]=1;
	}
}
int main()
{
	int n,a,b,i,j;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		if(a>1&&b>1)
		{
			puts("NO");
			continue;
		}
		if(n==2||n==3)
		{
			if(a==1&&b==1)
			{
				puts("NO");
				continue;
			}
		}
		mem(mp,0);
		if(a>b) work(a,b,n);
		else
		{
			work(b,a,n);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i^j) mp[i][j]^=1;
				}
			}
		}
		puts("YES");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d",mp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
