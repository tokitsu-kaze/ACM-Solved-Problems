
 #include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,ans,i,j,ii,jj,a[5][6],flag[111];
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<6;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				for(ii=0;ii<6;ii++)
				{
					for(jj=0;jj<6;jj++)
					{
						flag[(a[i][ii])*10+a[j][jj]]++;
					}
				}
				
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<6;j++)
			{
				flag[a[i][j]]++;
			}
		}
		ans=0;
		for(i=1;i<=100;i++)
		{
			if(!flag[i])
			{
				ans=i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}